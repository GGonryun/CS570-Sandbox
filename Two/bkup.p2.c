/* INCLUDES & DEPENDANCIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "getword.h"

/* DEFINITIONS */
#define MAX_ARGS 10
#define MAX_FILE 100
#define TRUE 1
#define FALSE 0

/* ASCI DECLARATIONS */
int parse();
void execute();
void build_array(char * a[]);
void empty_array(char * a[]);

/* GLOBAL FLAGS */
int f_terminate; 
int f_wait;
int f_push;
int f_pull;
int f_pipe;

/* GLOBAL STORAGE */
char * line[MAX_ARGS];
char push_file[MAX_FILE];
char pull_file[MAX_FILE];

//TODO: We need to add builtins for commands such as: (he will say later).
//TODO: Learn about file descriptors.
int main() 
{
        int length;

        //(void) build_array(line);
        for(;;) {
                /* reset global flags */
                f_terminate = FALSE;
                f_wait = FALSE;
                f_push = FALSE;
                f_pull = FALSE;
                f_pipe = FALSE;

                length = 0;
                /* Begin Shell */
                (void) printf(":570: ");
                length = parse();
                printf("length: %d\n", length);

                /* executing command */
                execute();
        }
        //(void) empty_array(line);
}

int parse() 
{
        int l, t;
        for(t = 0 ;l=getword(line[t]);) {
                if(-255 == l) {
                        f_terminate = TRUE;
                        break;        
                } else if (0 == l) {
                        break;
                } else if (strcmp(line[t], ">") == 0) {
                        f_push = TRUE;
                        (void) getword(push_file);
                } else if (strcmp(line[t], "<") == 0) {
                        f_pull = TRUE;
                        (void) getword(pull_file);
                } else if (strcmp(line[t], "|") == 0) {
                        f_pipe = TRUE;
                        //TODO: DO SOMETHING
                } else {
                        t++;
                }
        }

        //setting up the wait flag.
        if(strcmp(line[t-1], "&") == 0) {
                f_wait = TRUE;
                t--;
        }
        line[t] = NULL;
        return t;
}

void execute()
{
        printf("%s\n",line[0]);
}

void build_array(char *a[]) {
        int i;
        for(i = 0; i < MAX_ARGS; i++)
                a[i] = (char *) malloc (STORAGE*sizeof(char));
}

void empty_array(char * a[]) {
        int i;
        for(i = 0; i < MAX_ARGS; i++)
                free(a[i]);
}

