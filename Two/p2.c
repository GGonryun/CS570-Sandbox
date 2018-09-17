int parse();
void prompt();
void build_array(char * a[]);
void empty_array(char * a[]);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getword.h"

#define MAX 10
#define LENGTH 255

char *command[MAX]; //to be executed.
int terminate = 0;
int main() 
{
        (void) build_array(command);
        (void) shell_ui();
        (void) empty_array(command);
}


int shell_ui() {
        int l;
        for(;;) {
                prompt(); l = parse();
                /* preparing user input for execution */
                if(l <= 0)      
                        continue;
                if(*command[0] == EOF)
                        break;
        }
}

int parse() 
{
        int i;
        int l;
        for(i = 0; l = getword(command[i]); i++) {
                if(l==0) 
                        break;                 // reached the end of command.
                if(l==-255)
                        *command[i] = EOF;
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

