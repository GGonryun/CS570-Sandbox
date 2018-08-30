/*             multi.c
 *
 * Synopsis  - Displays a multiplication table for positive
 *             integer products between 0*0 and 3*4.
 *
 * Objective - Demonstrates multidimensional arrays and
 *             the ?: construct.
 */

/* Include Files */
#include <stdio.h>

/* Function Prototypes */
void printab( int rows, int columns, int array[][5] );          /* Note 1 */
/* PRECONDITION:  rows and columns contain the numbers of rows and 
 *                columns of array.
 *
 * POSTCONDITION: Displays the contents of an array of type int.
 */

int main( void )
{
    int multiarray[4][5],                                       /* Note 2 */
        row, column;

    for ( row = 0; row < 4; row++ )                             /* Note 3 */
        for ( column = 0; column < 5; column++ )
            multiarray[row][column] = row * column;

    printab( 4, 5, multiarray );
    return 0;
}

/*******************************printab()***********************/
                                                                /* Note 4 */
void printab( int rows, int columns, int array[][5] )
{
    int i = 0, j = 0;

    while ( i < rows ) {
        printf( "%d%c", array[i][j], ( j == columns-1 ) ? '\n' : '\t' ); /* Note 5 */
                                                                         /* Note 5 */
        ( j == columns - 1 ) ? i++,j=0 : j++;
    }
}