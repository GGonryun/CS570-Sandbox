#include <stdio.h>

main() 
{
  int c;
  while ((c = getchar()) != EOF) 
  {
    if(c == '\t') c = 't';
    else if(c == '\b') c = 'b';
    else if(c == '\\') c = '\\';
    putchar(c);
  }
}
