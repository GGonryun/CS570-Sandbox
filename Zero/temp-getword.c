#include <stdio.h>

int getword(char* w) {
    int c = getchar();
    if(c == EOF) {
        return -255;
    }
    return c;
}
