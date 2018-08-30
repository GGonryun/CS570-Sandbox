/*             do.c
 *
 * Synopsis  - A user is asked to enter an integer. The digits
 *             in the number are displayed in reverse order
 *             and then in the original order.
 *
 * Objective - Demonstrates the do-while statement and pass by
 *             value for parameters.
 */

/* Include Files */
#include <stdio.h>

/* Constant Declarations */
#define RADIX 10

/* Function Declarations */
void reverse( int number, int radix );
/* PRECONDITION:  number can be any non-negative decimal integer.
 *                radix is an integer representing the base.
 *
 * POSTCONDITION: The digits of number are displayed in reverse 
 *                order.
 */

int main( void )
{
    int number;

    printf( "Enter a decimal number: " );
    scanf( "%d", &number );

    printf( "\nDigits reversed: " );
    reverse( number, RADIX );
    printf( "Original number : %d\n", number );        /* Note 1 */
    return 0;
}

/******************************* reverse() ***********************/

void reverse( int number, int radix )
{
    do {                                               /* Note 2 */
        printf( "%d", number % radix );
        number /= radix;
    }
    while ( number != 0 );                             /* Note 2 */

    printf( "\n" );
}