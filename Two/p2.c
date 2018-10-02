/* Miguel Campos
 * Dr. John Carroll
 * CS570
 * 10/05/18
 * p2.c
 */

#include "p2.h"
#include "getword.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

#define TERMINATE -255
#define S_PUSH ">"
#define S_PULL "<"
#define S_PIPE "|"
#define S_WAIT "&"
#define SUCCESS 0
#define FAILURE -1

/* ========== GLOBAL BOIS ========== */
int f_terminate;
int f_push;
int f_pull;
int f_pipe;
int f_wait;
int f_cdir;
int f_break;
int nextline;

/* === CHARACTER AND STRING STORAGE === */
char *line[MAX_ARGS];
char tmp[MAX_ARGS][STORAGE];
char push_file[STORAGE];
char pull_file[STORAGE];
char pipe_comm[STORAGE];
char c_dir[STORAGE];

//TODO: DOCUMENT & DEFINE THE SHIT OUTTA THIS.
//TODO: GO THROUGH SPLINT AND FIX EVERYTHING AT THE END.
//TODO: ARE WE PASSING EVERYTHING? LETS DO SOME REFACTORING
//      AND CHECK ONCE THE AUTOGRADER IS READY.
int main() {
        /* === Catch Termination Signal === */
        //TODO: setpgid()
        (void) signal(SIGTERM, donothing);
        /* === Execute Shell === */
        for(;;) {
                pid_t childpid;
                int max = 0;
                f_push = f_pull = f_pipe = f_wait = f_cdir = nextline = FALSE;
        /* == Receiving & Validating User Input */
                printf(":cs570: ");
                max = parse();
                if(f_terminate) 
                        break;
                if(1 > max) {
                        if(f_push > 0 || f_pull > 0) 
                                fprintf(stderr, "Invalid Command: No process specified for redirection!\n");
                        continue;
                }
                if(1 < f_push) {
                        fprintf(stderr, "Operation not permitted: Too many output redirections found! [%d]!\n", f_push);
                        continue;
                } 
                if(1 < f_pull) {
                        fprintf(stderr, "Operation not permitted: Too many input redirections found! [%d]!\n", f_push);
                        continue;
                }
                if(NULL == line[nextline])
                        fprintf(stderr, "Invalid Command: No process specified!\n");
        /* === Handling Built-Ins === */
                if(SUCCESS == strcmp(line[0],"cd")) {
                        if(1 == max) 
                                line[1] = getenv("HOME");
                        if(2 < max)
                                fprintf(stderr,"Argument List Too Long: CD only takes 1 argument, you passed [%d] arguments!\n", max);
                        else if(-1 == chdir(line[1])) 
                                fprintf(stderr,"Invalid Directory: CD was unable to change directories to [%s]!\n",line[1]);
                        continue;
                }
        /* === Forking Children For Process Execution === */
                if(FAILURE == (childpid = fork()) ) {
                        fprintf(stderr, "System Failure: Unable to fork a new child process.");
                        exit(1);
                } else if(SUCCESS == childpid) {
                        inputmacro();
                        outputmacro();                      
                        if(0 < f_pipe)
                                pipemacro();
                        executemacro(line[nextline], line+nextline);
                        fflush(stdout);
                        exit(0);
                } else {
                        pid_t pid;
                        if(!f_wait)
                                for(; (childpid != pid);pid = wait(NULL));
                        else
                                printf("%s [%d]\n", line[nextline], childpid);
                }
        }
        /* === Exterminate Remaining Children === */
//        killpg(getpgrp(), SIGTERM);
        printf("p2 terminated.\n");
        exit(0);
}

/********************************************************************************
The parse function scans incoming user text, scans for any environment variables,
sets global flags for:
        1) > (push): redirects output towards the specified file.
        2) < (pull): redirects input from a specified file.
        3) $ (envr): locates a specific environment varibale.
        4) | (pipe): creates a pipeline for two processes to share.
        5) & (wait): sets the execution of a child process to be processed in
                     the background.
        6) EOF: terminates a command or the shell if its the only argument.
The parse function will return its total number of arguments passed.

The parse will scan for any metacharacters or words, if a word is found it will
be stored in our line. otherwise we will set appropriate flags and proceed to th-
e next scan. If our previous scan found a metacharacter we will handle the follo-
wing word depending on what the metacharacter requests.
        ex: metacharacter > will store the next word in the push_file variable.

********************************************************************************/
int parse() {
        int i, j, l;
        int check = 0;
        for(i = 0, j = 0; f_break = 0, l = getword(tmp[i]) ; i++) {
                if(TERMINATE == l) {
                        if(0 == j)  
                                f_terminate++; 
                        break;
                } 
        /* We must convert environment variables to strings. */ 
                if(0 > l) {
                        char *env;
                        if((env = getenv(tmp[i])) != NULL)
                                strcpy(tmp[i],env);
                }        
        /* We will store the argument as a file name, but we * 
         * do not want to handle metacharacters as filenames */
                if(check && f_push > 0) {
                        check--;
                        if(!(ismeta(tmp[i])))
                                strcpy(push_file, tmp[i]);
                        continue;
                } else if (check && f_pull > 0) {
                        check--;
                        if(!(ismeta(tmp[i])))
                                strcpy(pull_file, tmp[i]);
                        continue;
                }
        /* We want to warn ourselves if we find a metacharacter to make sure we  *
         * treat the next word as a special word and do something else. We only *
         * care about the LAST & we find so only the last &'s flag will pass.  */
                f_wait = 0;
                if (!(f_break) && SUCCESS == strcmp(tmp[i], S_PUSH)) {
                        f_push++;
                        check++;
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_PULL)) {
                        f_pull++;
                        check++;
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_PIPE)) {
                        f_pipe++;
                        line[j++] = NULL; 
                        nextline = j; // Starting location of next command.
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_WAIT)) {
                        f_wait++;
                        line[j++] = tmp[i];              
                } else {
                        line[j++] = tmp[i];
                }
        
        }        
        /* Activating background process flag and placing a  * 
         * command termination signal at the end accordingly */ 
        if(j > 0 && (NULL != line[j-1])) {
                if(f_wait && SUCCESS == strcmp(line[j-1], S_WAIT))
                        j--;
                else
                        f_wait = FALSE;}
        line[j] = NULL;
        return j;       //Return total line length.
}

/********************************************************************************
The output macro is in charge of redirecting user output if the flag is set.
The output macro will also handle any errors associated with locating, creating,
opening, and modifying a file. The output macro will replace stdout with a file-
descriptor of the output file.
********************************************************************************/
void outputmacro() {
        int out, flags, permissions;
        if(!f_push) 
                return;
    /* We are attempting to see if we can access the specified file
     * and if it already exists we can ignore it. */
        if(!access(push_file, F_OK)) {
                flags = (O_WRONLY);
                fprintf(stderr, "File Already Exists: cannot overwrite [%s]!\n",push_file);
                strcpy(push_file, "/dev/null");
        } else {
                flags = (O_WRONLY | O_CREAT | O_TRUNC);
        }
        permissions = (S_IRUSR | S_IWUSR);
    /* Redirecting all our output into the file we opened up. */ 
        if((out = open(push_file, flags, permissions)) < 0) {
                perror("unable to open file");
                exit(1);                  
        } 
        dupmacro(out, STDOUT_FILENO);
        closemacro(out);
}

/********************************************************************************
The input macro is in charge of redirecting user input if the flag is set.
The input macro will also handle any errors associated with locating, creating,
opening, and modifying a file. The input macro will replace stdin with a file-
descriptor of the input file.
********************************************************************************/
void inputmacro() {
        int in, flags;
    /* Background processes without input specified require */
    /* having their  input redirected to null. */
        if(!f_pull) {
                if(f_wait) 
                        strcpy(pull_file,"/dev/null");
                else            
                        return;
        }
    /* Access the file as read only for input, this also */
    /* helps prevent accidentally modifying a file. */    
        flags = (O_RDONLY);
        if((in = open(pull_file, flags)) == -1) {
                fprintf(stderr, "System Failure: We were unable to open the file [%s]\n", pull_file);
                exit(1);
        }
        dupmacro(in, STDIN_FILENO);
        closemacro(in);
}

/********************************************************************************
The pipe macro is in charge of creating a new pipe and connecting processes
through the pipe. It will also handle any errors related to creating the pipe,
along with hooking up the processes file descriptors to the pipe.
        pfd[0] represents the output side of the pipe.
        pfd[1] represents the input side of the pipe.
********************************************************************************/
void pipemacro() {
        int pfd[2];
        int grandchildpid;
        if(-1 == pipe(pfd)) {
                fprintf(stderr, "System Failure: Unable to create pipe!\n");
                exit(1);
        }
        if(FAILURE == (grandchildpid = fork())) {
                fprintf(stderr, "System Failure: Unable to fork child!\n");
                exit(1);
        } else if(SUCCESS == grandchildpid) { //Redirecting output to pfd[1]: parent Process.
                closemacro(pfd[0]);
                dupmacro(pfd[1],STDOUT_FILENO);
                closemacro(pfd[1]);
                executemacro(line[0],line);
                fflush(stdout);
                exit(0);
        } else {
                pid_t kpid; //Reading from pfd[0]: child Process.
                closemacro(pfd[1]);
                dupmacro(pfd[0],STDIN_FILENO);    
                closemacro(pfd[0]);
                fflush(stdout);
                for(; grandchildpid != kpid; kpid = wait(NULL));
        } 
}

void executemacro(char *file, char *args[]) {
        if(execvp(line[nextline],line+nextline) == -1) {
                fprintf(stderr,"No Such Process: execvp was unable to execute the process [%s]!\n", line[nextline]);
                exit(1);
        }
}

void dupmacro(int newfd, int oldfd) {
        if(dup2(newfd, oldfd) == -1) {
                fprintf(stderr, "System Failure: unable to set filedescriptors [new: %d, old: %d]!\n", newfd, oldfd);
                exit(2);
        }
}

void closemacro(int fd) {
        if(close(fd) == -1) {
                fprintf(stderr, "System Failure: unable to close file descriptor [%d]!\n", fd);
                exit(1); 
        }
}

int ismeta(char* s) {
        if( !(strcmp(s,">")) || !(strcmp(s,"<")) || !(strcmp(s,"|")) || !(strcmp(s,"&")) )
                return 1;
        else 
                return 0;
        
}

void donothing() { }
