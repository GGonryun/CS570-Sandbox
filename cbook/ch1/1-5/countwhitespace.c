#include <stdio.h>

main()
{
  int c, ws;
  ws = 0;
  while((c = getchar()) != EOF) 
  {
    if(c == '\n' || c == '\t' || c == ' ')
    {
      ++ws;
    }
  }
  printf("%1d\n",ws);
}
