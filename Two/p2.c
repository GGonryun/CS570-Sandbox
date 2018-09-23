#include "p2.h"

/* GLOBAL BOIS */
int f_terminate;
int f_push;
int f_pull;
int f_pipe;
int f_wait;

/* CHARACTER AND STRING STORAGE */
char *line[MAX_ARGS];
char tmp[MAX_ARGS][STORAGE];
char push_file[STORAGE];
char pull_file[STORAGE];

int main() {

        prepare();        

        int max = parse();
        int i;
        
        for(i = 0;i < max;i++) {
                printf("index: %d, word: %s\n",i,line[i]);
        }
        if(f_pull) {
                (void) redirectinput();
                printf("pullfile specified: %s\n",pull_file);
        }
        if(f_push) { 
                (void) redirectoutput();
                printf("pushfile specified: %s\n",push_file); 
        }
        if(f_wait) {
                printf("we're waiting!\n");
        }
}

int parse() {
        int i, j, l;
        for(i = 0, j = 0 ; (l = getword(tmp[i])) ; i++) {
                if(l == -255) { 
                        f_terminate = TRUE; break;
                } else if (strcmp(tmp[i], ">") == 0) {
                        f_push = TRUE;
                        getword(push_file);
                } else if (strcmp(tmp[i], "<") == 0) {
                        f_pull = TRUE;
                        getword(pull_file);
                } else if (strcmp(tmp[i], "|") == 0) {
                        f_pipe = TRUE;
                } else {
                        line[j++] = tmp[i];
                }
        }
        if(strcmp(line[j-1], "&") == 0) {
                f_wait = TRUE;
                j--;
        } 
        line[j] == NULL;
        return j;
}

void redirectoutput() {
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
        if(close(out) < 0) {
                perror("unable to close file descriptor");
                exit(3);
        }
}

void redirectinput() {
        int in;
        int flags = (O_RDONLY);
        if((in = open(pull_file, flags)) < 0) {
                perror("unable to open file");
                exit(1);
        }
        if(dup2(in, STDIN_FILENO) < 0) {
                perror("unable to set file descriptor");
                exit(2);
        }
        if(close(in) < 0) {
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

