#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int main() {
        char src[] = "hello;! ";
        char *env = getenv("HOME");
        strcat(src, env);
        printf("%s && %d \n", src, strlen(env));
}
