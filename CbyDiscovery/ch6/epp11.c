/*             epp11.c
*/
	
/* Include Files */
#include <stdio.h>
	
/* Function Prototypes */
void stackit( void );
/* Fill in the PRECONDITION and POSTCONDITION 
*/
int main( void )
{
    stackit();
    return 0;
}
	
void stackit( void )
{
    int iochar;
	
    if (( iochar = getchar() ) != '\n' ) {
        stackit();
        putchar( iochar );
    }
}