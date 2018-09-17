int parse();
void prompt();
void build_array(char * a[]);
void empty_array(char * a[]);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "getword.h"

#define MAX 10
#define LENGTH 255
#define TRUE 1
#define FALSE 0

char *command[MAX]; //to be executed.
/* global flags */
int f_wait;



int main() 
{
        (void) build_array(command);
        (void) shell_ui();
        (void) empty_array(command);
}


int shell_ui() {
        int l;
        int kidpid;

        for(;;) {
                /* reset global flags */
                f_wait = FALSE;
                kidpid = 0;
               
                /* preparing user input for execution */
                prompt(); l = parse();
                if(0 >= l)      
                        continue;
                if(EOF == *command[0])
                        break;
                
                /* executing command */        
                if(-1 == (kidpid = (int)fork())) {      //fork process.
                        exit(1);                        //cannot fork.
                } else if ( 0 == kidpid) {              //in child. 
                        (void) sleep(2);
                        exit(0);
                } else {                                //in parent.
                        printf("parent is locked out.\n");
                        for(;f_wait>0;) {                       //waiting for child process.
                                pid_t pid;
                                pid = wait(NULL);
                                if(pid == kidpid)
                                        break;
                        }
                        printf("parent is ready now. \n");
                }
        }
}

int parse() 
{
        int i;
        int l;
        for(i = 0; l = getword(command[i]); i++) {
                
                /* terminating command */
                if(0 == l) 
                        break;                
                else if(-255 == l) {
                        *command[i] = EOF;
                        break;
                }
                /* activating global flags for execution */
                if(0 == strcmp(command[i],"&")) 
                        f_wait++;
        }
        return i;
}


void prompt() {
        printf(":cs570: ");
}

void build_array(char *a[]) {
        int i;
        for(i = 0; i < MAX; i++)
                a[i] = (char *) malloc (LENGTH*sizeof(char));
}

void empty_array(char * a[]) {
        int i;
        for(i = 0; i < MAX; i++)
                free(a[i]);
}

