/*             goto.c
 *
 * Synopsis  - Expects a stream of digits in input. The digits
 *             are converted to an integer value and output.
 *
 * Objective - To illustrate error handling with the goto
 *             statement.
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* Function Prototypes */
int convert( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: Reads a line from standard input until either a 
 *                blank, an end of line or a nondigit is seen. 
 *                Returns the int value of the input string in the 
 *                first two cases; displays an error message and 
 *                terminates the program in the last case.
 */

int main( void )
{
    printf( "Enter a positive integer > " );
                                                       /* Note 1 */
    printf( "The value entered was %d.\n", convert () );
    exit( 0 );
}
/******************************* convert() ***********************/

int convert( void )
{
    int ch,
        sum = 0;

    while ((( ch = getchar() ) != ' ' )&& ( ch != '\n' )) {

        if ( !isdigit( ch ) )
            goto error;                                /* Note 2 */
        sum = sum * 10 + ( ch - '0' );
    }
    return ( sum );
                                                       /* Note 3 */
error:  printf( "Nondigit in input. Program terminated.\n" );
        exit( 1 );
}