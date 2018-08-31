/* Include Files */
#include <stdio.h>
#define ON 1
#define OFF 0


int getword(char* w)
{
    int c;
    int wordlength = 0;
    int multiplier = 1;
    int status = OFF;
    while(1) {
        c = getchar();
        if(c == ';') {
            wordlength--; 
            break;
        }
        else if (c == EOF) return -255;
        if(c == ' ') status = OFF;
        else if(c == '$' && status == OFF) { 
            multiplier *= -1; 
            status = ON;
        } else if(status == OFF) {
            status = ON;
        }
        if(status = ON) { 
            wordlength++;
        }   

    }
    return multiplier * wordlength;
    
}
