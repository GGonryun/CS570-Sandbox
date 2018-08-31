#include <stdio.h>

int getword( char* w )
{
    int iochar;
    int state = 0;
    int wordlength = 0;
    int multiplier = 1;
    for(;;) {
        iochar = getchar();
        if(iochar == EOF) {
            wordlength = 255;
            multiplier = -1;
            break;
        } else if(iochar == ' ') {
            if(state == 1) {
                break;
            } else {
            wordlength = 0;
            }
        } else if(iochar == ';') {
            if(state == 1) {
                break;
            } else {
                wordlength++;
                break;
            }
        } else if(iochar == '\n') {
            if(state == 1) {
                break;
            } else {
                wordlength++;
                break;
            }
        } else if (iochar == '$') {
            if(state == 1) {
                wordlength++;
            } else {
                multiplier *= -1;
            }
        } else {
            if(state == 0) {
                state == 1;
            }
            wordlength++;
        }
    }
    return multiplier * wordlength;
}
