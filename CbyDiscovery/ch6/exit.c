/*             exit.c
 *
 * Synopsis  - Reads a stream of digits for its input, converts
 *             the input to an integer value, and displays it.
 *             Finding a nondigit in input is an error.
 *
 * Objective - To illustrate error handling with the exit()
 *             library function.
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h>                                     /* Note 1 */
#include <stdlib.h>                                    /* Note 2 */

/* Function Prototypes */
int convert( void );
/* PRECONDITION: none 
 *
 * POSTCONDITION: Reads standard input until either a blank, an end 
 *                of line or a nondigit is found. If only digits are 
 *                found, the function returns the converted value as 
 *                type int. Otherwise, the function error() is 
 *                called.
 */

void error( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: Displays an error message and terminates the 
 *                program with exit value 1.
 */

int main( void )
{
    printf( "Enter a positive integer > " );
                                                       /* Note 3 */
    printf( "The value entered was %d.\n", convert() );
    exit( 0 );                                         /* Note 4 */
}

/******************************* convert() ***********************/

int convert( void )
{
    int ch,
        sum = 0;
    while ((( ch = getchar() ) != ' ' )&& (ch != '\n' )) {

    if ( !isdigit( ch ) )                              /* Note 1 */
        error();
        sum = sum * 10 + ( ch - '0' );                 /* Note 5 */
    }
    return ( sum );
}

/******************************* error() *************************/

void error( void )
{
    printf( "Nondigit in input. Program terminated.\n" );
    exit( 1 );                                         /* Note 6 */
}