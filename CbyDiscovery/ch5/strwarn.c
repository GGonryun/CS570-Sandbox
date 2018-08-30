/*             strwarn.c
 *
 * Synopsis  - Attempts to accept input of a line of text with 
 *             the library function gets().  There is an error
 *             in the program because space for the input line
 *             was not allocated.
 *
 * Objective - To point out a common error made by beginning C
 *             programmers.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{
    char *prompt = "Enter a line of text.\n> ";
    char *inputptr, *inputptr1;                        /* Note 1 */

    printf( prompt );
    inputptr1 = gets( inputptr );                      /* Note 2 */
    if ( inputptr1 != NULL )
        puts( inputptr1 );
    else
        puts( "Error in input\n" );
    return 0;
}