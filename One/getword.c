
/*  Miguel Campos
 *  Dr. John Carroll
 *  CS570
 *  8/31
 *  getword.c
 */
#include <stdio.h>
#include <string.h>
#include <strings.h>


#define EOS '\0'
//Delimiters
#define BLANK ' '
#define NEWLINE '\n'
#define SEMI ';'
#define PULL '<'
#define PUSH '>'
#define PIPE '|'
#define WAIT '&'
#define TILDE '~'

#define MONEY '$'
#define BREAK '\\'

//States determining whether we are [IN]side or [OUT]side a word.
#define IN 1
#define OUT 0

        int getword(char* w) {
        int c;           //character from getchar() is stored in here.
        int letters = 0; //total letters in word.
        int state = OUT; //storing state.
        int multiplier = 1; //used to determine if '$' was used.
        for(;;) {
                c = getchar();

                if(letters == 254) {
                        w[letters] = EOS;
                        break;
                }

                if(state == OUT){
                        if (c == BLANK) {
                                state = OUT;
                        } else if (c == EOF) {
                                w[letters] = EOS;
                                return -255;
                        } else if (c == NEWLINE || c == SEMI) {
                                w[letters] = EOS;
                                break;
                        } else if (c == PUSH || c == PIPE || c == WAIT) {
                                w[letters++] = c;
                                w[letters] = EOS;
                                break;
                        } else if (c == PULL) {
                                w[letters++] = c;
                                c = getchar();
                                if (c == PULL) {
                                        w[letters++] = c;
                                        w[letters] = EOS;
                                        break;
                                } else {
                                        ungetc(c,stdin);
                                        w[letters] = EOS;
                                        break;
                                }
                                
                        } else if (c == MONEY) {
                                state = IN;
                                multiplier *= -1;
                                continue;
                        } else { 
                                state = IN;
                        }
                } 
                
                if(state == IN) { 
                        if(c == BLANK) {
                                w[letters] = EOS;
                                break;
                        } else if (c == SEMI || c == NEWLINE) {
                                w[letters] = EOS;
                                ungetc(c,stdin);
                                break;
                        } else if (c == PUSH || c == PULL || c == PIPE || c == WAIT) {
                                w[letters] = EOS;
                                ungetc(c,stdin);
                                break;
                        } else if (c == EOF) {
                                w[letters] = EOS;
                                break;
                        } else if (c == BREAK) {
                                c = getchar();
                                w[letters++] = c;                               
                        } else {
                                w[letters++] = c;
                        }
                }
        }
        return letters * multiplier;        
}
