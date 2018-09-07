#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int main() {
        char src[] = "hello;! ";
        char *env = getenv("HOME");
        strcat(src, getenv("HOME"));
        printf("%s", src);
}
