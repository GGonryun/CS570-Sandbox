/*             squares.c
 *
 * Synopsis  - Displays results of the macros SQUARE(x),
 *             SQR(x), SQR2(x) and the function square(x).
 *
 * Objective - To illustrate some of the differences between
 *             macros and functions: how substitutions take
 *             place and how macros are expanded.
 */

/* Include Files */
#include <stdio.h>

/* Macro Definitions */
#define SQUARE( x )            x * x                      /* Note 1 */
#define SQR( x )               (( x ) * ( x ))            /* Note 2 */

int SQR2_x;                                               /* Note 3 */
#define SQR2( x )              ( SQR2_x=( x ), SQR2_x * SQR2_x )

/* Function Declarations */
int square( int x );
/* PRECONDITION:  x is an int
 *
 * POSTCONDITION: returns the square of its argument
 */

int main( void )
{
    int a;

    a = 3;                                                /* Note 4 */
    printf( "square( a ) is %d.\n", square( a ));
    printf( "SQUARE( a ) is %d.\n", SQUARE( a ));
    printf( "SQR( a ) is %d.\n", SQR( a ));
    printf( "SQR2( a ) is %d.\n", SQR2( a ));

                                                          /* Note 5 */
    printf( "\nsquare( a+1 ) is %d\n", square( a+1 ));
    printf( "SQUARE( a+1 ) is %d.\n", SQUARE( a+1 ));
    printf( "SQR( a+1 ) is %d.\n", SQR( a+1 ));
    printf( "SQR2( a+1 ) is %d.\n", SQR2( a+1 ));

                                                          /* Note 6 */
    printf( "\nsquare( a++ ) is %d, and ", square( a++ ));
    printf( "a is %d\n", a );

    a = 3;
    printf( "SQUARE( a++ ) is %d, and ", SQUARE( a++ ));
    printf( "a is %d\n", a );

    a = 3;
    printf( "SQR2( a++ ) is %d, and ", SQR2( a++ ));
    printf( "a is %d\n", a );

    a = 3;
    printf( "SQR( a++ ) is %d, and ", SQR( a++ ));
    printf( "a is %d\n", a );
    return 0;
}

/******************************* square() ************************/

int square( int x )                                       /* Note 7 */
{
    return ( x * x );
}