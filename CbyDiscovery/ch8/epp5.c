/*  epp5.c
 */

/* Include Files */
#include <stdio.h>

/* Global Variables */
    int   W, X, Y, I;

/* Function Prototypes */
/* Add PRECONDITION and POSTCONDITION information for 
 * each function
 */
void demonstrate( int *y, int v );
	
int main( void )
{
    W = 3;
    X = 2;
    Y = 1;
    I = 2;

    demonstrate( &W, Y );
    printf( "%d, %d, %d, %d\n", W, X, Y, I );

    demonstrate( &I, X );
    printf( "%d, %d, %d, %d\n", W, X, Y, I );
    return 0;
}

void demonstrate( int* Y, int V )
{
    int   W, X;

    X  = (*Y) * V;
    W  = X / 2;
    *Y = W - V;
    I++;
    printf( "%d, %d, %d, %d\n",  V, W, X, *Y );
}