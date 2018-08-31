#include <stdio.h>
#define NULL_TOKEN '\0'
#define NEWLINE_TOKEN '\n'
#define SEMI_TOKEN ';'
#define BLANK_TOKEN ' '
#define SPECIAL_TOKEN '$'
#define IN 1
#define OUT 0

int getword(char* w) {
    int c;
    int letters = 0;
    int state = OUT;
    int multiplier = 1;
    for(;;) {
        c = getchar();
        if(state == OUT){
            if (c == BLANK_TOKEN) {
                state = OUT;
            } else if (c == EOF) {
                w[letters] = NULL_TOKEN;
                return -255;
            }  else if (c == SEMI_TOKEN || c == NEWLINE_TOKEN) {
                w[letters] = NULL_TOKEN;
                break;
            } else if (c == SPECIAL_TOKEN) {
                state = IN;
                multiplier *= -1;
                continue;
            } else {
                state = IN;
            }
        }
        if(state == IN) { 
            if(c == BLANK_TOKEN) {
                w[letters] = NULL_TOKEN;
                break;
            } else if (c == SEMI_TOKEN || c == NEWLINE_TOKEN) { //SEMI_TOKEN & NEWLINE_TOKEN both have the same behavior when inside a word.
                w[letters] = NULL_TOKEN;
                ungetc(SEMI_TOKEN,stdin);
                break;
           } else if (c == EOF) {
                w[letters] = NULL_TOKEN;
                ungetc(EOF,stdin);
                break;
           } else {
                w[letters++] = c;
           }
        }
    }
    return letters * multiplier;
        
}
