int parse();

#include <stdio.h>
#include <string.h>
#include "getword.h"

#define MAX 10
#define LENGTH 255

char line[MAX][LENGTH];

int main() 
{
        int i, j;
        for(i = 0, j = parse(); i < j ; i++)
                printf("%s\n", line[i]);       
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
