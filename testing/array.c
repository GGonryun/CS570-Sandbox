#include <stdio.h>

int main() {
        char a[] = "hello";
        char b[] = "world";
        char c[] = "poop";

        printf("word one: %s\nword two: %s\nword three: %s\n",a,b,c);
        
        char * all[2] = {a,b,c};

        printf("word one: %s\nword two: %s\nword three: %s\n",all[0],all[1],all[2]);

}
