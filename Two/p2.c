/*  M****l C****s
 *  Dr. J**n C*****l
 *  CS###
 *  ##/##/18
 *  p2.c
 */
/* INCLUDES & DEPENDANCIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "getword.h"

/* DEFINITIONS */
#define MAX 10
#define LENGTH 255
#define TRUE 1
#define FALSE 0

/* ASCI DECLARATIONS */
int user_input();
int parse();
int execute(int *kp);
void build_array(char * a[]);
void empty_array(char * a[]);

/* GLOBAL FLAGS */
char *command[MAX]; 
int f_wait;

int main() 
{
        int length;
        int kidpid;
        int kidstatus;
        (void) build_array(command);
        for(;;) {
                /* reset global flags */
                f_wait = FALSE;
                kidpid = 0;

                /* preparing user input for execution */
                length = user_input();
                if(0 >= length)
                        continue;
                if(EOF == *command[0])
                        break;

                /* executing command */
                kidstatus = execute(&kidpid);
        }
        (void) empty_array(command);
}

int user_input() {
        printf(":cs570: ");
        return parse();
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


int execute(int *kp)
{
        int status = 0;
        int failure = 0;
                                        //Create a fork ::
        if(-1 == (*kp = (int)fork())) { //:: the fork has failed.
                exit(1);
        } else if ( 0 == *kp) {         //:: execute the command as child.
                //(void) sleep(2); //<-- add this for testing child delays.
                failure = execvp(command[0],command);
                if(failure) {
                        printf("Execvp failed: %d. \"%s\" is not a command!\n",
                               failure,command[0]); 
                } else 
                        exit(0);
        } else {                        //:: wait for child to execute as parent.
                pid_t pid;              //if & flag is there, we do not wait.
                for(; (0 == f_wait) && (pid != *kp); pid = wait(&status));

                return status;
        }

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

