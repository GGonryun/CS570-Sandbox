/* Miguel Campos
 * Dr. John Carroll
 * CS570
 * 10/05/18
 * 2.c
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
        (void) signal(SIGTERM, donothing);
        /* === Execute Shell === */
        for(;;) {
        /* === Preparation === */
                pid_t childpid;
                int max;
                prepare();
                printf(":cs570: ");
                max = parse();

        /* === Preprocessing === */
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
                        redirectinput();
                        redirectoutput();
                        
        /* === Preparing Pipe === */
                        if(f_pipe > 0) {
                                int pfd[2];
                                int grandchildpid;
                                if((pipe(pfd)) == -1) {
                                        perror("unable to create pipe!");
                                        exit(10);
                                }
                                
                                if(-1 == (grandchildpid = fork())) {
                                        perror("unable to create child");
                                        exit(1);
                                } 
                                
                                if(grandchildpid == 0) {
                                        
                                        //Redirecting output to pfd[1]: Parent Process.
                                        close(pfd[0]);
                                        dup2(pfd[1],STDOUT_FILENO);
                                        close(pfd[1]);
                                        if((execvp(line[0],line)) == -1) {
                                                perror("execvp failed!");
                                                exit(1);
                                        }
                                        fflush(stdout); //FFLUSH HERE
                                        exit(0);
                                } else {
                                        pid_t kpid;
                                        //Reading from pfd[0]: Grandchild Process.
                                        close(pfd[1]);
                                        dup2(pfd[0],STDIN_FILENO);
                                        close(pfd[0]);
                                        fflush(stdout);
                                        for(; grandchildpid != kpid; kpid = wait(NULL));
                                }
                        }
                        
                        // ^ THIS SHOULD TURN INTO A FUNCTION

                        if(execvp(line[nextline],line+nextline) == -1) {
                                fprintf(stderr,"cannot execute %s", line[nextline]);
                               // perror("Cannot execute");
                                exit(1);
                        }
                        if(f_wait) {
                                printf("child [%d] done\n", getpid());
                        }
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
        killpg(getpgrp(), SIGTERM);

        printf("p2 terminated.\n");
        exit(0);
}

int parse() {
        int i, j, l;
        int check = 0;
        for(i = 0, j = 0 ; (l = getword(tmp[i])) ; i++) {
        /* Checking for terminating signal */
                if(l == TERMINATE) {
                        if(0 == j)  
                                f_terminate++; 
                        break;
                } 
        /* Prog4: Checking for environment variables */ 
                if(l < 0) {
                        char *env;
                        if((env = getenv(tmp[i])) != NULL)
                                strcpy(tmp[i],env);
                }
        
        /* Catching flags from previous word. */ 
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
        /* Set flags for the next word or store current word. */
                if (strcmp(tmp[i], S_PUSH) == 0) {
                        f_push++;
                        check++;
                } else if (strcmp(tmp[i], "<") == 0) {
                        f_pull++;
                        check++;
                } else if (strcmp(tmp[i], "|") == 0) {
                        f_pipe++;
                        line[j++] = NULL; 
                        nextline = j; //location of the next command.
                } else {
                        line[j++] = tmp[i];
                }
        
        }        
        /* Preparing flags for waiting "&" */
        if(j > 0 && line[j-1] != NULL) {
                if(f_wait && strcmp(line[j-1], "&") == 0)
                        j--;
                else
                        f_wait = FALSE;
        } 
        /* End of argument */
        line[j] = NULL;
        return j; // return total line length.
}

void redirectoutput() {
        int out, flags, permissions;
        if(!f_push) 
                return;
    /* If the file already exists don't write over it just leave it alone and throw */
    /* away your output otherwise, go ahead and write to the file that we've found. */
        if(!access(push_file, F_OK)) {
                strcpy(push_file, "/dev/null");
                flags = (O_WRONLY);
                errno = EEXIST;
                perror("Cannot write to file");
        } else {
                flags = (O_WRONLY | O_CREAT | O_TRUNC);
        }
        permissions = (S_IRUSR | S_IWUSR);
    /* Redirecting all our output into the file we opened up. */ 
        if((out = open(push_file, flags, permissions)) < 0) {
                perror("unable to open file");
                exit(1);                  
        } 
        if(dup2(out, STDOUT_FILENO) < 0) { 
                perror("unable to set file descriptor");
                exit(2);
        }
        if(close(out) == -1) {
                perror("unable to close file descriptor");
                exit(3);
        }
}
void redirectinput() {
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
                perror("unable to open file");
                exit(1);
        }
        if(dup2(in, STDIN_FILENO) == -1) {
                perror("unable to set file descriptor");
                exit(2);
        }
        if(close(in) == -1) {
                perror("unable to close file descriptor");
                exit(3);
        }
}


/* Initializing the shell & next line. */
void prepare() {
        f_terminate = FALSE;
        f_push = FALSE;
        f_pull = FALSE;
        f_pipe = FALSE;
        f_wait = FALSE;
        nextline=0;
}

int ismeta(char* s) {
        if( !(strcmp(s,">")) || !(strcmp(s,"<")) || !(strcmp(s,"|")) || !(strcmp(s,"&")) )
                return 1;
        else 
                return 0;
        
}

void donothing() { }
