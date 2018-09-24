#include "p2.h"

/* ========== GLOBAL BOIS ========== */
int f_terminate;
int f_push;
int f_pull;
int f_pipe;
int f_wait;
int f_cdir;

/* === CHARACTER AND STRING STORAGE === */
char *line[MAX_ARGS];
char tmp[MAX_ARGS][STORAGE];
char push_file[STORAGE];
char pull_file[STORAGE];
char pipe_comm[STORAGE];
char c_dir[STORAGE];


int main() {
        //TRY TO HANDLE CATCHING KILL SIGNAL
        struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_handler = donothing;
        if(sigaction(SIGTERM, &sa, NULL) == -1) {
                perror("sigterm problems");
                exit(1);
        }
        
        for(;;) {
                prepare();
                pid_t childpid;
                int max, i;
                        
                //displaying tail of current working directory path in prompt
                for(getcwd(c_dir,sizeof(c_dir)),i = strlen(c_dir) - 1; c_dir[i] != '/'; i--);                 
                printf("%s:570: ", &(c_dir[++i])); 

                max = parse();

                /* ==== PREPROCESSING CHECKS ==== */
                if(f_terminate) break;
                if(max < 1) continue;
                
                /* === HANDLING BUILTINS ==== */
                                
                if(strcmp(line[0],"cd") == 0) {
                        if(max == 1) line[1] = getenv("HOME");
                        if(chdir(line[1]) == -1) perror("did not change directory: ");           
                        continue;
                }

                /* ==== EXECUTING CHILDREN ==== */
                if(-1 == (childpid = fork())) {
                        perror("unable to create child");
                        exit(1);
                } else if( 0 == childpid) {

                        redirectinput();
                        redirectoutput();

                        if(execvp(line[0],line) == -1) {
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
        killpg(getpgrp(),SIGTERM);
        printf("\np2 terminated.\n");
        exit(0);
}

int parse() {
        int i, j, l;
        for(i = 0, j = 0 ; (l = getword(tmp[i])) ; i++) {
                if(l == -255) {
                        if(0 == j)  
                                f_terminate = TRUE; 
                        break;
                } else if (l < 0) 
                        strcpy(tmp[i],getenv(tmp[i]));

                if(TRUE == f_push) {
                        f_push++;
                        strcpy(push_file, tmp[i]);
                        continue;
                } else if (TRUE == f_pull) {
                        f_pull++;
                        strcpy(pull_file, tmp[i]);
                        continue;
                } else if (TRUE == f_pipe) {
                        f_pipe++;
                        strcpy(pipe_comm, tmp[i]);
                        continue;
                }

                if (strcmp(tmp[i], ">") == 0) {
                        f_push = TRUE;
                } else if (strcmp(tmp[i], "<") == 0) {
                        f_pull = TRUE;
                } else if (strcmp(tmp[i], "|") == 0) {
                        f_pipe = TRUE;
                } else {
                        line[j++] = tmp[i];
                }
        
        }        
        if(j > 0) {
                if( strcmp(line[j-1], "&") == 0) {
                        f_wait = TRUE;
                        j--;
                }
        } 
        line[j] = NULL;
        return j;
}

void redirectoutput() {
        if(!f_push) {
                return;
        }
        int out;
        int flags = (O_WRONLY | O_CREAT | O_TRUNC);
        int permissions = (S_IRUSR | S_IWUSR);
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
        if(!f_pull) {
                if(f_wait)      strcpy(pull_file,"/dev/null");
                else            return;
        }        
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

void prepare() {
        int i;
        char cwd[STORAGE];
        getcwd(cwd,sizeof(cwd));

        for(i = strlen(cwd) -1; cwd[i] != '/'; i--);
        
        f_terminate = FALSE;
        f_push = FALSE;
        f_pull = FALSE;
        f_pipe = FALSE;
        f_wait = FALSE;
}

void donothing(int signum) {

}
