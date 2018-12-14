/* ====== BRINGING IN DEPENDENCES ====== */
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
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* ========== GLOBAL VARIABLES ========== */
int f_terminate, f_push, f_pull, f_pipe, f_wait, f_cdir, f_break, f_here, f_tilde, f_env,  cmd[MAX_PIPES];
char *line[ARGUMENTS], tmp[ARGUMENTS][STORAGE], push_file[STORAGE], pull_file[STORAGE], delimiter[STORAGE], current_path[STORAGE];

int main() {
        /* Create a process group for ourselves and our children * 
         * but the parent will ignore the termination signal     */
        if(FAILURE == setpgid(getpid(),0)) {
                fprintf(stderr,"System Failure: we are unable to set our process group!");
                exit(EXIT_FAILURE);
        }
        if(SIG_ERR == signal(SIGTERM, donothing)) {
                fprintf(stderr,"System Failure: unable to redirect our sigterm signal!");
                exit(EXIT_FAILURE);
        }
        /* Shell execution begins here, we will first clear out flags *
         * and flush any old output before asking for user input.     */
        current_path[0] = '\0';
        for(;;) {
                pid_t childpid;
                int total_words = 0;
                f_push = f_pull = f_pipe = f_wait = f_cdir = f_here = f_tilde = f_env = FALSE;
                push_file[0] = pull_file[0] = delimiter[0] = '\0';
                printf("%s:570: ", current_path); 
                total_words = parse(); 
        /* Parse may return funky values since it doesnt validate input, checking here so * 
         * that parse doesn't make the shell shit the bed prematurely and error out.      */
                if(0 < f_terminate) 
                        break;
                if(f_tilde == -1) {
                        fprintf(stderr, "Invalid User: the user `%s` could not be found!\n", tmp[0]);
                        continue;
                }
                if(f_env == -1) {
                        fprintf(stderr, "Invalid Environment Variable: Unable to locate environment variable `%s`\n", tmp[0]);
                        continue;
                }
                if(1 > total_words) {
                        if(f_push > 0 || f_pull > 0) 
                                fprintf(stderr, "Invalid Command: No process specified for redirection!\n");
                        continue;
                }
                if(f_pull > 0 && f_here > 0) {
                        fprintf(stderr, "Ambiguous redirection: only use << or < not both!\n");
                        continue;
                }
                if(FLAG_LIMIT < f_push) {
                        fprintf(stderr, "Operation not permitted: Too many output redirections found! [%d]!\n", f_push);
                        continue;
                } 
                if(FLAG_LIMIT < f_pull) {
                        fprintf(stderr, "Operation not permitted: Too many input redirections found! [%d]!\n", f_pull);
                        continue;
                }
                if(NULL == line[cmd[f_pipe]]) {
                        fprintf(stderr, "Invalid Command: No command specified for execution!\n");
                        continue;
                }
                
        /* We will handle builtins before we attempt to fork any new children, *
         * this will ensure our children operate in the correct environments.  */
                if(SUCCESS == strcmp(line[0],"cd")) {
                        char *last;
                        if(1 == total_words) 
                                line[1] = getenv("HOME");
                        if(2 < total_words) {
                                fprintf(stderr,"Argument List Too Long: CD only takes 1 argument, you passed [%d] arguments!\n", total_words-1);
                                continue;
                        } else if(-1 == chdir(line[1])) {
                                fprintf(stderr,"Invalid Directory: CD was unable to change directories to [%s]!\n",line[1]);
                                continue;
                        }                       
                        getcwd(current_path,STORAGE);
                        last = basename(current_path);
                        strcpy(current_path, last);
                        continue;
                }
                if(SUCCESS == strcmp(line[0],"environ")) {
                                char *env;
                        if(1 == total_words) {
                                fprintf(stderr, "Insufficient Arguments: You did not provide enough arguments!\n");
                        } else if(2 == total_words) {
                                if(!(env = getenv(line[1])) ) {
                                        printf("\n");
                                } else {
                                        printf("%s\n",env);
                                }
                        } else if(3 == total_words) {
                                if(FAILURE == setenv(line[1],line[2],1)) {
                                        fprintf(stderr, "System Failure: Unable to set environment variable [%s]=[%s]!", line[1],line[2]);
                                }
                        } else {
                                fprintf(stderr, "Excessive Arguments: environ takes 2 or less arguments, you passed [%d] arguments!\n", total_words-1);
                        }
                        continue;
                }
        /* We will make sure to pass a clean buffer to our child */
                if(FAILURE == fflush(stdout)) {
                        fprintf(stderr, "System Failure: Unable to flush the contents of buffer [%s]\n", "stdout");
                        exit(EXIT_FAILURE);
                }
                if(FAILURE == fflush(stderr)) {
                        fprintf(stderr, "System Failure: Unable to flush the contents of buffer [%s]\n", "stderr");
                        exit(EXIT_FAILURE);
                }
        /* We will fork a child to process our input from parse. The child will self-destruct upon completion or 
           it may be terminated by the parent if necessary. */
                hereismacro(); //will request user input.
                if(FAILURE == f_here) {
                        continue;
                }
                if(FAILURE == (childpid = fork()) ) {
                        fprintf(stderr, "System Failure: Unable to fork a new child process.");
                        exit(EXIT_FAILURE);
                } else if(SUCCESS == childpid) {
                        int num;
                        inputmacro();
                        outputmacro();
                        num = pipemacro();
                        executemacro(line[cmd[num]], line+cmd[num]);
                        exit(EXIT_SUCCESS);
                } else {
                        pid_t pid = -1;
                        if(!f_wait)
                                for(; (childpid != pid);pid = wait(NULL));
                        else
                                printf("%s [%d]\n", line[cmd[f_pipe]], childpid);
                        if(f_here) 
                                remove(HEREIS_FILE);
                }
        }
        /* === Exterminate Remaining Children === */
        if(FAILURE == killpg(getpgrp(), SIGTERM)) {
                fprintf(stderr,"System Failure: we were unable to kill the process group specified [%d]!\n",getpgrp());
                exit(EXIT_FAILURE);
        }
        printf("p2 terminated.\n");
        exit(EXIT_SUCCESS);
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
Since metacharacters will set a c_flag instead, the second pass can do some extr-
a processing on it's file before accepting it such as validating that our file i-
s not a metacharacter, but we can add things such as input from environment vari-
ables. for example: "< $SUPERFILE" which we would be able to set later.
********************************************************************************/
int parse() {
        int i, j, l;
        int c_push = 0, c_pull = 0, c_here = 0, c_tilde = 0; //internal flags, tells us when to store contents of push & pull & here.
        for(i = 0, j = 0; f_break = FALSE, l = getword(tmp[i]) ; i++) {
                if(TERMINATE == l) {
                        if(0 == j)  
                                f_terminate++; 
                        break;
                } 
        // We must convert environment variables to strings.
                if(0 > l) {
                        char *env;
                        if((env = getenv(tmp[i])) != NULL)
                                strcpy(tmp[i],env);
                        else {
                                f_env = -1;
                                strcpy(tmp[0],tmp[i]);
                                break;
                        }
                }
        /* We will store the argument as a file name, but we * 
         * do not want to handle metacharacters as filenames */
                if(c_push && f_push) {
                        c_push = FALSE;
                        if(!(ismeta(tmp[i])))
                                strcpy(push_file, tmp[i]);
                        continue;
                } else if (c_pull && f_pull) {
                        c_pull = FALSE;
                        if(!(ismeta(tmp[i])))
                                strcpy(pull_file, tmp[i]);
                        continue;
                } else if (c_here && f_here) {
                        c_here = FALSE;
                        if(!(ismeta(tmp[i])))
                                strcpy(delimiter, tmp[i]);
                        continue;
                } else if (c_tilde && f_tilde) {
                        //builds the string composed of a path to the user.
                        char *token = strtok(tmp[i],"/");
                        char *path = strtok(NULL,"\0");
                        char user[STORAGE];
                        c_tilde = FALSE;
                        //finds a user and decorates the string with the path.
                        (void) strcpy(user, finduser(token));
                        if(path != NULL) {
                                (void) strcat(user, "/");
                                (void) strcat(user, path);
                        }
                        //places the string in a temporary buffer to be placed in local storage.
                        (void) strcpy(tmp[i], user);

                }
        /* We want to warn ourselves if we find a metacharacter to make sure we  *
         * treat the next word as a special word and do something else. We only  *
         * care about the LAST & we find so only the last & flag will be passed. */
                f_wait = 0;
                if (!(f_break) && SUCCESS == strcmp(tmp[i], S_PUSH)) {
                        f_push++;
                        c_push++;
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_PULL)) {
                        f_pull++;
                        c_pull++;
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_PIPE)) {
                        line[j++] = NULL; 
                        cmd[++f_pipe] = j; // Starting location of next command.
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_WAIT)) {
                        f_wait++;
                        line[j++] = tmp[i];              
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_HERE)) {
                        f_here++;
                        c_here++;
                } else if (!(f_break) && SUCCESS == strcmp(tmp[i], S_TILDE)) {
                        if(l == 1) {
                                strcpy(tmp[i], finduser(getenv("USER")));
                                line[j++] = tmp[i];
                        } else {
                                f_tilde++;
                                c_tilde++;
                        }
                } else {
                        line[j++] = tmp[i];
                }
        
        }        
        /* We are calculating the location of the NULL termination pointer *
         * which depends on whether or not we have found an & at the end.  */ 
        if(j > 0 && (NULL != line[j-1]))
                if(f_wait && SUCCESS == strcmp(line[j-1], S_WAIT))
                        j--;
                else
                        f_wait = FALSE;
        line[j] = NULL;
        return j;       //Return total line length.
}

/********************************************************************************
The find user macro will tokenize each line of the file specified by our 
DIRECTORY variable. If the first word of the line matches the value we're looking
for `who` then we will return the 5th value delimited by ":". We will launch
an error if we were unable to find the user specified and store the name in
a temporary location to be fetched immediately after with the corresponding
error message.
********************************************************************************/
char* finduser(char* who) {
        FILE *fp;
        char *line = NULL;
        char *token = NULL;
        size_t len = 0;
        
        fp = fopen(DIRECTORY,"r");
        //as long as the file has a next line.
        while(FAILURE != (getline(&line, &len, fp))) {
                token = strtok(line,":");
                //if we match the first token in the line.
                if(SUCCESS == strcmp(token,who)) {
                        int i;
                        //then select the fifth token in the line.
                        for(i = 0; i < 5; i++) {
                                token = strtok(NULL,":");
                        }
                        return token;
                }
        }
        //otherwise store the name and report an error.
        f_tilde = -1;
        (void) strcpy(tmp[0], who);
        return "ERR";
        
}
/********************************************************************************
The hereismacro handles the "<<" metacharacter. When a "<<" character is found
by parse we will trigger a flag which will allow entry into the code. Once we're
inside the macro we will scan each word presented to us by "stdin" and put
them into a buffer, we will then check to see if the line put into the buffer
matches the delimiter. If it does we terminate, otherwise we store the word in
a temporary file which we will clean up later.
********************************************************************************/
void hereismacro() {
        if(f_here > 0) {
                FILE *stream;
                char *nl;
                size_t n = 0, len;
                char buffer[STORAGE];

                if(delimiter[0] == '\0') {
                        fprintf(stderr, "No Delimiter Specified: '<<' (hereis) expects a delimiter [ex: cat << test]!\n");
                        f_here = -1;
                        return;
                }
                
                stream = fopen(HEREIS_FILE,"w+");
                for(;;) {
                        if(0 == (len = getline(&nl, &n, stdin))) 
                                break; //END OF FILE.                               
                        strcpy(buffer,nl);
                        if(buffer[len-1] == '\n') 
                                buffer[len-1] = '\0';
                        if(SUCCESS == (strcmp(buffer,delimiter))) 
                                break;
                        else 
                                (void) fwrite(nl,len,1,stream);
                 }
                 fclose(stream);
                 strcpy(pull_file, HEREIS_FILE);
                 f_pull++;
        }
}
/*******************************************************************************
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
                fprintf(stderr, "File Already Exists: cannot overwrite [%s]!\n",push_file);
                exit(EXIT_FAILURE);
        } else {
                flags = (O_WRONLY | O_CREAT);
        }
        permissions = (S_IRUSR | S_IWUSR);
    /* Redirecting all our output into the file we opened up. */ 
        if(FAILURE == (out = open(push_file, flags, permissions))) {
                fprintf(stderr, "File System Error: cannot open the target file [%s]!\n", (strcmp(push_file,"")) ? push_file : "NULL");
                exit(EXIT_FAILURE);
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
        if(FAILURE == (in = open(pull_file, flags))) {
                fprintf(stderr, "File Not Found: unable to open the file [%s]\n", (strcmp(pull_file,"")) ? pull_file : "NULL");
                exit(EXIT_FAILURE);
        }
        dupmacro(in, STDIN_FILENO);
        closemacro(in);
}

/*******************************************************************************
The pipe macro is in charge of creating a new pipe and connecting processes    *
through the pipe. It will also handle any errors related to creating the pipe, *
along with hooking up the processes file descriptors to the pipe.              *
        Connect standard in to fd[EVEN] to receive data.                       *
        Connect standard out to fd[ODD] to send data.                          *
        Returns the location of the command to run.                            *
     ***************************************************************************
NOTE:* The order of dup's is very important, we want to ensure that we do not. *
     * accidentally step over any of the previously setup redirections. This   *
     * specific order ensures that the process redirecting its output into the *
     * pipe does not accidentally overwrite any previous file descriptors. We  * 
     * allows the user to execute commands w/o worrying about semantic suicide.*
     * ex: cat < readfile | >writefile tr a-Z | grep apples                    *
********************************************************************************/
int pipemacro() {
        int pfd[20], i, j, k, c_pid, last_cmd = f_pipe;
        if(0 != f_pipe) {
                for(i = 0; i < f_pipe; i++) 
                        pipe(pfd+(i*2));
        }
        for(j = last_cmd, k = 0; j >= 0; j--, k+=2) {  
                if(j != last_cmd) 
                        dupmacro(pfd[k-1],STDOUT_FILENO); // sending data
                if(j == 0) 
                        break;
                c_pid = fork();
                if(SUCCESS < c_pid) {
                        dupmacro(pfd[k],STDIN_FILENO); // receive data
                        break;
                }
        }
        if(0 != f_pipe) {
                for(i = 0; i < f_pipe*2; i++)
                        closemacro(pfd[i]);
        }
        return j;
}

/********************************************************************************
the executemacro is a simple macro that will help us handle any errors associated
with attempting to execute a command using the execvp systemcall.
********************************************************************************/
void executemacro(char *command, char *args[]) {
        if(FAILURE == execvp(command,args)) {
                fprintf(stderr,"No Such Process: execvp was unable to execute the process [%s]!\n", command); 
                exit(EXIT_FAILURE);
        }
}
/********************************************************************************
the dupmacro is a simple macro that will help us handle any errors associated
with attempting to connect filedescriptors. The dupmacro uses command dup2, to 
overwrite the old file descriptor with a new file descriptor.
********************************************************************************/
void dupmacro(int newfd, int oldfd) {
        if(FAILURE == dup2(newfd, oldfd)) {
                fprintf(stderr, "System Failure: unable to set filedescriptors [new: %d, old: %d]!\n", newfd, oldfd);
                exit(EXIT_FAILURE);
        }
}
/********************************************************************************
the closemacro is a simple macro that will help us handle any errors associated
with attempting to close preexisting file descriptors. The closemacro uses the
system call close(fd) to seal up unused or unnecessary filedescriptors.
********************************************************************************/
void closemacro(int fd) {
        if(close(fd) == -1) {
                fprintf(stderr, "System Failure: unable to close file descriptor [%d]!\n", fd); 
                exit(EXIT_FAILURE); 
        }
}
/********************************************************************************
ismeta is a helper function that will help us analyze whether or not the incoming
string is a metacharacter. this check is most useful to help us prevent accident-
ally loading up a metacharacter as a file name such as "cat < <". This limitation
is to force the user to differentiate between metacharacters and filenames when
using this bash shell.
********************************************************************************/
int ismeta(char* s) {
        if( (SUCCESS == strcmp(s,">")) || (SUCCESS == strcmp(s,"<")) || (SUCCESS == strcmp(s,"|")) || (SUCCESS == strcmp(s,"&")) )
                return TRUE;
        else 
                return FALSE;
}

/********************************************************************************
donothing is a simple helper function which does absolutely nothing. It probably
does something in the background that C would do when declaring a function but,
it really doesn't do much. Trust me.
********************************************************************************/
void donothing() { }
