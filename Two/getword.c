/*  M***l C***s
 *  Dr. J***n C***l
 *  CS###
 *  ##/##/18
 *  getword.c
 */

#include "getword.h"
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


//TODO: DOCUMENT THE SHIT OUTTA THIS.
//TODO: WE NEED TO SETUP A FLAG TO IGNORE OUR & FLAG.
//TODO: FIX ALL THESE DEFINES AND TOSS THEM INTO GETWORD.H INSTEAD

extern int f_wait;
int getword(char * w) {

        short c;                 //character from getchar() is stored in here.
        short letters = 0;              //total letters in word.
        unsigned short state = OUT;     //storing state.
        signed short multiplier = 1;    //used to determine if '$' was used.
        char *env = getenv("HOME");     //gets current home directory.

        while(letters < STORAGE-1) {
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
                                f_wait++;
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
                                strcpy(w,env);
                                letters = (short)strlen(env);
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
                                if(c == NEWLINE) continue;                                
                        }
                        w[letters++] = c;
                }
        }
        w[letters] = EOS;
        return letters * multiplier;        
}
