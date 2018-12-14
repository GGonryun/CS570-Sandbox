#include "getword.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define EOS '\0'
#define BLANK ' '
#define NEWLINE '\n'
#define SEMI ';'
#define PULL '<'
#define PUSH '>'
#define PIPE '|'
#define TILDE '~'
#define MONEY '$'
#define BREAK '\\'
#define WAIT '&'

#define TERMINATE -255
#define IN 1
#define OUT 0

extern int f_break; //from p2.c, lets us know that a '\' was encountered.
int getword(char * w) {

        short c;                 //character from getchar() is stored in here.
        short letters = 0;              //total letters in word.
        unsigned short state = OUT;     //storing state.
        signed short multiplier = 1;    //used to determine if '$' was used.
        while(letters < STORAGE-1) {
                c = getchar();
                if(state == OUT){
                        if (c == BLANK) {
                                state = OUT;
                        } else if (c == EOF) {
                                w[letters++] = EOS;
                                multiplier = TERMINATE;
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
                                w[letters++] = c;
                                c = getchar();
                                if(isalpha(c) || isdigit(c)) {
                                        multiplier++;
                                }
                                ungetc(c,stdin);
                                break;
                        } else { 
                                state = IN;
                        }
                } 
                
                if(state == IN) { 
                        if(c == BLANK) {
                                break;
                        } else if (c == EOF || c == SEMI || c == NEWLINE || c == PUSH || c == PULL || c == PIPE || c == WAIT) {
                                ungetc(c,stdin); //returning the metacharacter to stdin for a post-processing check on the next call.
                                break;
                        } else if (c == BREAK) {
                                f_break++;
                                c = getchar();
                                if(c == NEWLINE) continue;                                
                        }
                        w[letters++] = c;
                }
        }
        w[letters] = EOS;
        return letters * multiplier;        
}
