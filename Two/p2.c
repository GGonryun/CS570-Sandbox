#include "p2.h"

/* ========== GLOBAL BOIS ========== */
int f_terminate;
int f_push;
int f_pull;
int f_pipe;
int f_wait;

/* === CHARACTER AND STRING STORAGE === */
char *line[MAX_ARGS];
char tmp[MAX_ARGS][STORAGE];
char push_file[STORAGE];
char pull_file[STORAGE];
char pipe_comm[STORAGE];


int main() {
        for(;;) {
                prepare();
                pid_t childpid;
                int max;
                        
                printf(":570: "); max = parse();

                /* ==== PREPROCESSING CHECKS ==== */
                if(f_terminate) break;
                if(max < 1) continue;

                /* ==== EXECUTING CHILDREN ==== */
                if(-1 == (childpid = fork())) {
                        perror("unable to create child");
                        exit(1);
                } else if( 0 == childpid) {

                        redirectinput();
                        redirectoutput();
                      /* == INCHILD ==
                        int i;
                        printf("child says:\n");
                        for(i = 0; i < max; i++) {
                                sleep(1);
                                printf("index: %d, word %s\n", i, line[i]);
                        }
                        if(f_pull) {
                                printf("pullfile specified: %s\n", pull_file);
                        }
                        if(f_push) {
                                printf("pushfile specified: %s\n", push_file);
                        }
                      */
                        if(execvp(line[0],line) == -1) {
                                perror("execvp failed!");
                                exit(1);
                        }
                        exit(0);
                } else {
                        pid_t pid;
                        for(;!(f_wait) && (childpid != pid);pid = wait(NULL));
                                
                        //printf("parent says: we are done waiting for child\n");
                        
                }
        }
}

int parse() {
        int i, j, l;
        for(i = 0, j = 0 ; (l = getword(tmp[i])) ; i++) {
                if(l == -255) {
                        if(0 == j)  
                                f_terminate = TRUE; 
                        break;
                } else if (strcmp(tmp[i], ">") == 0) {
                        f_push = TRUE;
                        getword(push_file);
                } else if (strcmp(tmp[i], "<") == 0) {
                        f_pull = TRUE;
                        getword(pull_file);
                } else if (strcmp(tmp[i], "|") == 0) {
                        f_pipe = TRUE;
                        getword(pipe_comm);
                } else {
                        line[j++] = tmp[i];
                }
        
        }        
        if(j > 0 && strcmp(line[j-1], "&") == 0) {
                f_wait = TRUE;
                j--;
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
        f_terminate = FALSE;
        f_push = FALSE;
        f_pull = FALSE;
        f_pipe = FALSE;
        f_wait = FALSE;
}

