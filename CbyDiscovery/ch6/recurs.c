/*             recurs.c
 *
 * Synopsis  - Inputs a positive integer, calculates its 
 *             factorial, and outputs the result.
 *
 * Objective - A simple example of a recursive function.
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h>                                    /* Note 1 */
#include <stdlib.h>

/* Function Prototypes */
int factorial( int n );
/* PRECONDITION:  n can be any non-negative integer.
 *
 * POSTCONDITION: Uses a recursive algorithm to calculate the
 *                factorial of its argument. It returns the value
 *                n factorial.
 */
int convert( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: Reads standard input until either a blank, an end 
 *                of line or a nondigit is found. If only digits are 
 *                found, the function returns the converted value as 
 *                type int. Otherwise, the function error() is called.
 */

void error( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: Displays an error message and terminates the 
 *                program with exit value 1.
 */

int main( void )
{
    int n;

    printf( "Program to Calculate Factorials.\n" );
    printf( "------- -- --------- -----------\n" );
    printf( "\nEnter a positive integer value : " );

    n = convert();                                     /* Note 2 */

    printf( "\n%d! is %d.\n", n, factorial( n ) );
    return 0;
}

/******************************* factorial() *********************/

int factorial( int n )
{
    if ( n == 0 )                                      /* Note 3 */
        return ( 1 );
    else
        return ( n * factorial( n-1 ) );               /* Note 4 */
}

/******************************* convert() ***********************/

int convert( void )
{
    int ch,
        sum = 0;

    while ((( ch = getchar() ) != ' ' ) && (ch != '\n' )) {
        if ( !isdigit( ch ) )                          /* Note 1 */
            error();
        sum = sum * 10 + ( ch - '0' );                 /* Note 4 */
    }
    return ( sum );
}

/******************************* error() *************************/

void error( void )
{
    printf( "Nondigit in input. Program terminated.\n" );
    exit( 1 );
}