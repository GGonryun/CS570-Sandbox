#include <stdio.h>

main() 
{
  float fahr, celsius ;
  float lower, upper, step ;
  lower = 0 ;
  upper = 1000 ;
  step = 20 ;
  celsius = lower ;
  printf("%s    %s\n", "Celsius", "Fahrenheit") ;
  while(celsius <= upper) {
    fahr = (9.0/5.0 * celsius) + 32;
    printf("%6.1f            %3.0f\n", celsius, fahr) ;
    celsius = celsius + step ;
  }
}
