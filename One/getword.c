/*  Miguel Campos
 *  Dr. John Carroll
 *  CS570
 *  8/31
 *  getword.c
 */

#include "getword.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define EOS '\0'

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

#define IN 1
#define OUT 0

int getword(char* w) {

        int c;                  //character from getchar() is stored in here.
        int letters = 0;        //total letters in word.
        int state = OUT;        //storing state.
        int multiplier = 1;     //used to determine if '$' was used.
        
        while(letters < STORAGE) {
                c = getchar();

                if(state == OUT){
                        if (c == BLANK) {
                                state = OUT;
                        } else if (c == EOF) {
                                w[letters++] = EOS;
                                multiplier = -255;
                                break;
                        } else if (c == NEWLINE || c == SEMI) {
                                break;
                        } else if (c == PUSH || c == PIPE || c == WAIT) {
                                w[letters++] = c;
                                break;
                        } else if (c == PULL) {
                                w[letters++] = c;
                                c = getchar();
                                if (c == PULL) {
                                        w[letters++] = c;
                                        break;
                                } else {
                                        ungetc(c,stdin);
                                        break;
                                }
                        } else if (c == MONEY) {
                                state = IN;
                                multiplier *= -1;
                                continue;
                        } else if (c == TILDE) {
                                state = IN;
                                char *env = getenv("HOME");
                                strcpy(w,env);
                                letters = strlen(env);
                                state = IN;
                                continue;                             
                        } else { 
                                state = IN;
                        }
                } 
                
                if(state == IN) { 
                        if(c == BLANK) {
                                break;
                        } else if (c == EOF || c == SEMI || c == NEWLINE || c == PUSH || c == PULL || c == PIPE || c == WAIT) {
                                ungetc(c,stdin);
                                break;
                        } else if (c == BREAK) {
                                c = getchar();                               
                        }
                        w[letters++] = c;
                }
        }
        w[letters] = EOS;
        return letters * multiplier;        
}
