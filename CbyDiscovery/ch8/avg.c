/*             avg.c
 *
 * Synopsis  - Computes and displays the average of
 *					a set of up to 100 integers.
 *
 * Objective - To illustrate the syntax of a function returning
 *             a noninteger value. Also illustrates the use of
 *             the value returned by scanf().
 */

/* Include Files */
#include <stdio.h>

/* Constant Declarations */
#define MAX 100

/* Function Prototypes */
float average( int *intarray, int count );              /* Note 1 */
/* PRECONDITION:  intarray is the address of an array of ints. It 
 *                must be declared by the calling function. count is 
 *                the number of items in intarray{}.
 *
 * POSTCONDITION: Calculates and returns the average of the integers 
 *                in the array intarray. 
 */

int getinputvalues( int *valarray );
/* PRECONDITION:  valarray is the address of an array of ints. It 
 *                must be declared by the calling function.
 *
 * POSTCONDITION: Reads integers from the keyboard until a 
 *                noninteger is found. Puts the input into the
 *                parameter valarray[]. Returns the number of 
 *                integers entered. 
 */

int main( void )
{
    int count;
    int values[MAX];

    printf( "Enter your data now. ");
    printf( "Enter one integer per line.\n" );
    printf( "Enter 'Q' when you want to quit.\n" );

    count = getinputvalues( values );                /* Note 2 */
                                                     /* Note 3 */
    printf( "The average is %5.2f.\n", average( values, count ));
    return 0;
}

/*******************************getinputvalues()****************/

int getinputvalues( int *valarray )                  /* Note 4 */
{
    int i = 0;

    printf( ">  " );
                                                     /* Note 5 */
    while ( i < MAX && scanf( "%d", valarray + i )) {
        i++;
        printf( ">  " );
    }
    return ( i );
}

/*******************************average()***********************/

float average( int *intarray, int count )            /* Note 6 */
{
    int i, sum = 0;

    if ( count != 0 ) {
        for ( i = 0; i < count; i++ )
        sum += intarray[i];
        return ( ( float ) sum / count );            /* Note 7 */
    }
    else
        return ( 0.0 );                              /* Note 8 */
}