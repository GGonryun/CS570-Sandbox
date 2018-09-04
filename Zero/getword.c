
/*  Miguel Campos
 *  Dr. John Carroll
 *  CS570
 *  8/31
 *  getword.c
 */
#include <stdio.h>

//The null token is used to end the output returned to w.
#define END_WORD '\0'
//Tokens
#define BLANK_TOKEN ' '
#define NEWLINE_TOKEN '\n'
#define SEMI_TOKEN ';'
#define SPECIAL_TOKEN '$'
//States determining whether we are [IN]side or [OUT]side a word.
#define IN 1
#define OUT 0

/*  Details: The getword function allows us to grab individual characters from the input
 *           stream in order to form words delimited by "terminating tokens" & "meta 
 *           tokens". Terminating tokens will end a word and output it's length, meta
 *           tokens denote a special action will take place.
 *           For the scope of this function any non-terminating, non-meta token is called 
 *           a "character".
 *           A sequence of "characters" then forms a "word", we return the word and it's
 *           length to the caller through a pointer to an array and it's return function
 *           respectively.
 *  Tokens: 
 *      1) BLANK_TOKEN:     Terminating, non-meta token. 
 *                          They will be ignored by the program. 
 *                          suggested: ' '
 *      2) SEMI_TOKEN:      Terminating, meta token. This token will produce output
 *                          of 0 when reached outside of a word.
 *                          suggested: ';'
 *      3) NEWLINE_TOKEN:   Terminating, meta token. Behaves similar to SEMI_TOKEN.
 *                          suggested: '\n'
 *      4) SPECIAL_TOKEN:   Nonterminating, meta token. When found within a word it
 *                          acts like a regular character. Otherwise it will output
 *                          a negative wordlength without counting itself.
 *                          suggest: '$' 
 */ 
int getword(char* w) {
    int c;           //character from getchar() is stored in here.
    int letters = 0; //total letters in word.
    int state = OUT; //storing state.
    int multiplier = 1; //used to determine if '$' was used.
    for(;;) {
        c = getchar();
        if(state == OUT){
            if (c == BLANK_TOKEN) {
                state = OUT;
            } else if (c == EOF) {
                w[letters] = END_WORD;
                return -255;
            }  else if (c == SEMI_TOKEN || c == NEWLINE_TOKEN) {
                w[letters] = END_WORD;
                break;
            } else if (c == SPECIAL_TOKEN) {
                state = IN;
                multiplier *= -1;
                continue;
            } else { //if we encounter a non-meta & non-terminating token.
                state = IN;
            }
        }

        if(state == IN) { 
            if(c == BLANK_TOKEN) {
                w[letters] = END_WORD;
                break;
            } else if (c == SEMI_TOKEN || c == NEWLINE_TOKEN) {
                w[letters] = END_WORD;
                ungetc(SEMI_TOKEN,stdin);
                break;
           } else if (c == EOF) {
                w[letters] = END_WORD;
                ungetc(EOF,stdin);
                break;
           } else { //if we encounter a non-meta & non-terminating token.
                w[letters++] = c;
           }
        }
    }
    return letters * multiplier;
        
}
