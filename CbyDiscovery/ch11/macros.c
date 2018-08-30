/*             macros.c
 *
 * Synopsis  - Accepts input of two integers from the keyboard 
 *             and displays the maximum of the two values.
 *
 * Objective - Will illustrate the expansion of macros by the
 *             preprocessor.
 */

/* Include Files */
#include <stdio.h>                                        /* Note 1 */
#include <ctype.h>                                        /* Note 2 */

/* Macro Definitions */
#define MAX(a, b)      (a > b) ? a : b                    /* Note 3 */

/* Function Declarations */
int getint( int *val );
/* PRECONDITION:  val contains the address of an int
 *
 * POSTCONDITION: Reads a line of input and converts input digits to 
 *                a value of type int and stores the result in its 
 *                parameter; returns a 0 for success and a 1 if any 
 *                nondigit is found; in the latter case, the 
 *                contents of val are set to 0
 */

int main( void )
{
    int x, y;

    printf( "Calculating the maximum of two numbers.\n" );
    printf( "Please enter the first nonnegative number : " );
    getint( &x );
    printf( "Please enter the second nonnegative number : " );
    getint( &y );
    printf( "The maximum of %d and %d is %d.\n",x, y, MAX( x,y ));
                                                          /* Note 4 */
    return 0;
}

/******************************* getint() ************************/

int getint( int *val )
{
    int iochar, num;

    num = 0;
    while (( iochar = getchar() ) != '\n' ) {            /* Note 5 */
        if ( isdigit( iochar ))                          /* Note 6 */
            num = 10*num + iochar - '0';
        else {
            printf( "Illegal input - %c\n", iochar );
                                                         /* Note 7 */
            while (( iochar = getchar() ) != '\n' )
            ;
            *val = 0;
            return( 1 );
        }
    }
    *val = num;
    return ( 0 );
}
