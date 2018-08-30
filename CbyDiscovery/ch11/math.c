/*             math.c
 *
 * Synopsis  - Accepts input of values for x and n and displays 
 *             the calculated values from the pow(), sqrt() and 
 *             tan() functions.
 *
 * Objective - To illustrate error handling with the 
 *             mathematical functions in the ANSI C library.
 */

/* Include Files */
#include <math.h>
#include <stdio.h>
#include <errno.h>                                    /* Note 1 */
#include <stdlib.h>

/* Function Declarations */
void error( char *s );
/* PRECONDITION:  s contains the address of a string
 *
 * POSTCONDITION: checks the value of errno, and if it is nonzero, 
 *                issues an error message
 */

int main( void )
{ 
    double n, x, y;
    char buff[50];

    printf( "Enter a value for n: " );
    n = strtod( gets( buff ), NULL );
    printf( "Enter value for x: " );
    x = strtod( gets( buff ), NULL );
    printf( "x is %5.2f.\n", x );
    printf( "n is %5.2f.\n", n );
    y = sqrt( x );                                     /* Note 2 */
    error( "sqrt" );
    printf( "sqrt(%4.2f) is %5.2f\n",x, y );           /* Note 3 */
    y = tan( x );                                      /* Note 4 */
    error( "tan" );
    printf( "tan(%4.2f) is %5.2f.\n", x, y );
    y = pow( x, n );                                   /* Note 5 */
    error( "pow" );
    printf( "pow(%4.2f, %4.2f) is %5.2f.\n", x, n, y );
    return 0;
}

/******************************* error() *************************/

void error( char *s )
{
    if ( errno )                                       /* Note 6 */
        perror( s );
    errno = 0;                                         /* Note 7 */
}
