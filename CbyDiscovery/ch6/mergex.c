/*             mergex.c
 *
 * Synopsis  - Allows a user to input elements into an array,
 *             sorts the array, and displays it in sorted order.
 *
 * Objective - To provide a program to test the merge sort
 *             algorithm.
 */

/* Include Files */
#include "mergsort.h"                                  /* Note 1 */
#include <stdio.h>
#include <ctype.h>
#include "mergsort.c"                                  /* Note 2 */

/* Constant Declarations */
#define DONE   0                                       /* Note 3 */
#define MORE   1
#define ERROR -1
/* Function Prototypes */
void print_array( int array[], int first, int num);
/* PRECONDITION:  array is the array of ints to be displayed. first 
 *                and num are integer indices for array.
 *
 * POSTCONDITION: Displays the elements of an array of ints from the
 *                position with index first to the position with 
 *                index num, inclusive.
 */

int fill_array( int empty[], int max_array );
/* PRECONDITION:  empty is the integer array to fill.
 *
 * POSTCONDITION: Allows the user to enter integers for an array of
 *                integers. Returns the number of elements entered
 *                into the array.
 */

int get_int( int *intptr );
/* PRECONDITION:  intptr contains the address of the integer 
 *                variable that will hold the input.
 *
 * POSTCONDITION: Accepts input of an integer from standard input.
 *                Returns the integer in the location pointed to by 
 *                intptr, and returns DONE if user signals quit, 
 *                ERROR if a nondigit was seen, or MORE if neither 
 *                of the above occurred.
 */

int main( void )
{
    int num;
    int array[MAX_ARRAY];

    num = fill_array( array, MAX_ARRAY );
    merge_sort( array, 0, num-1 );
    print_array( array, 0, num-1 );
    return 0;
}

/******************************* fill_array() ********************/

int fill_array( int empty[], int max_array)
{
    int count = -1,
        more = MORE;

    printf( "Enter your integers now. Enter 'Q' to quit\n" );
    printf( "%3d : ", ++count + 1 );

    while  ( count < max_array) {
        more = get_int( empty + count );

        if ( more == ERROR ) {                          /* Note 4*/
            printf( "Error in input - Try again\n" );
            printf( "%3d : ", count+1 );
            continue;
        }

        if ( !more )                                    /* Note 5*/
            break;
        printf( "%3d : ", ++count+1 );
    }
    return ( count );
}

/******************************* print_array() *******************/

void print_array( int array[], int first, int num )
{
    int index;

    for ( index = first; index <= num; index++ )
        printf( "%3d: %5d\n", index+1, array[index] );
}

/******************************* get_int() ***********************/

int get_int (int *intptr)
{
    int ch;
    char remainder[80];
    int digit_count = 0;

    *intptr = 0;
    while ( isdigit(ch = getchar() )) {
                                                        /* Note 6*/
        *intptr = *intptr * 10 + ( ch - '0' );
        digit_count++;
    }
    switch ( ch ) {                                     /* Note 7*/
        case 'Q':
        case 'q':
                   gets( remainder );                   /* Note 8*/
                   return ( DONE );
        case ' ': 
                   gets( remainder );
        case '\n':
                   if ( digit_count )
                       return ( MORE );
                   else
                       return ( ERROR );
        default:
                   gets( remainder );
                   return ( ERROR );
    }
}