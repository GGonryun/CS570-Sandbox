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

char *line[MAX];

int main() 
{
        (void) build_array(line);
        for(;;) {
                prompt();
                int i, j;
                for(i = 0, j = parse(); i < j ; i++)
                        printf("%s ", line[i]);
                printf("\n");       
        }
        (void) empty_array(line);
}


int parse() 
{
        int i;
        int l;
        for(i = 0; l = getword(line[i]); i++) {
                if(l==0) break;
                if((strcmp(line[i],"<<")) == 0) printf("double pull\n"); 
        }
        return i;
}


void prompt() {
        printf(":cs570 :");
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

