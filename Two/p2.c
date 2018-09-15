int parse();

#include <stdio.h>
#include "getword.h"

char words[100];

int main() {
        int c;
        int total_words;

        for(;;) {
        printf(":570 :");
        total_words = parse();
        }       
}

int parse() {
        int i = 0;
        int c;
        char word[255];
        for(;;) {
                c = getword(word);
                words[i++] = word;
        }
        words[i] = NULL;
        return 0;
                
        
}

