#include "p2.h"

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

//TODO: ADD IN GETCHAR A WAY FOR US TO SET A FLAG FOR OUR &.
//TODO: WE CAN USE "extern int foo;" TO BRING IN A VARIABLE FROM ELSEWHERE.
//TODO: THAT WAY WE CAN HANDLE THE \& PROPERLY.

int main() {
        /* === Catch Signal === */
        
        (void) signal(SIGTERM, SIG_IGN);
        
        //struct sigaction sa;
        //memset(&sa, 0, sizeof(sa));
        //sa.sa_handler = donothing;
        //if(sigaction(SIGTERM, &sa, NULL) == -1) {
        //        perror("sigterm problems");
        //        exit(1);
        //}   
        /* === Shell === */
        for(;;) {
                pid_t childpid;
                int max;
                
                prepare();
                printf(":cs570: "); fflush(stdout);
                                        
                max = parse();

                /* ==== PREPROCESSING CHECKS ==== */
                if(f_terminate) break;
                if(max < 1) {
                        if(f_push > 0 || f_pull > 0) {
                                errno = 3;
                                (void) perror("No command found!");
                        }
                        continue;
                }
                if(f_push > 1) {
                        errno = 1;
                        (void) perror("Too many pushes \'>\'");
                        continue;
                } 
                if(f_pull > 1) {
                        errno = 1;
                        (void) perror("Too many pulls \'<\'");
                        continue;
                }
                if(line[nextline] == NULL) {
                        errno = 3;
                        perror("No command found!");
                }
                
                /* === HANDLING BUILTINS ==== */
                if(strcmp(line[0],"cd") == 0) {
                        if(max == 1) line[1] = getenv("HOME");
                        if(max > 2) {
                                errno = 7; 
                                perror("Cannot change directories! cd expected only 1 argument!");
                        } else if(chdir(line[1]) == -1) 
                                perror("did not change directory: ");           
                        
                        continue;
                }

                /* ==== EXECUTING CHILDREN ==== */
                if(-1 == (childpid = fork())) {
                        perror("unable to create child");
                        exit(1);
                } else if( 0 == childpid) {
                        
                        redirectinput();
                        redirectoutput();
                        
                        // CREATING A PIPE HERE AND STUFF
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
                                        exit(0);
                                } else {
                                        //Reading from pfd[0]: Grandchild Process.
                                        close(pfd[1]);
                                        dup2(pfd[0],STDIN_FILENO);
                                        close(pfd[0]);

                                        pid_t kpid;
                                        for(; grandchildpid != kpid; kpid = wait(NULL));
                                }
                        }
                        
                        // ^ THIS SHOULD TURN INTO A FUNCTION

                        if(execvp(line[nextline],line+nextline) == -1) {
                                perror("execvp failed!");
                                exit(1);
                        }
                        if(f_wait) {
                                printf("child [%d] done\n", getpid());
                        }
                        exit(0);
                } else {
                        pid_t pid;
                        if(!f_wait)
                                for(; (childpid != pid);pid = wait(NULL));
                        else
                                printf("child [%d]\n", childpid);
                                
                }
        }
//        killpg(getpgrp(),SIGTERM);

        printf("\np2 terminated.\n");
        exit(0);
}

int parse() {
        int i, j, l;
        int check = 0;
        for(i = 0, j = 0 ; (l = getword(tmp[i])) ; i++) {
        /* Checking for terminating signal */
                if(l == -255) {
                        if(0 == j)  
                                f_terminate++; 
                        break;
                } 
        /* Prog4: Checking for environment variables */
                if(l < 0) {
                        char *env;
                        if((env = getenv(tmp[i])) == NULL)
                                strcpy(tmp[i],"INVALID ENV");
                        else 
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
                if (strcmp(tmp[i], ">") == 0) {
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
        int in;
        int flags = (O_RDONLY);
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
