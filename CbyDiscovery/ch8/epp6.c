/*  epp6.c
 */

/* Include Files */
#include <stdio.h>

/* Global Variables */
int int1 = 7,
    int2 = 8,
    int3 = 9;

/* Function Prototypes */
/* Add PRECONDITION and POSTCONDITION information for 
 * each function
 */
void p1( int *x, int y );

int main( void )
{
    int int3, int4, int5;

    int1 = 1;
    int2 = 2;
    int3 = 3;
    int4 = 4;
    int5 = 5;
    p1( &int3, int4 );
    printf( "int1 %d, int2 %d, int3 %d, int4 %d, int5 %d\n", int1, int2, int3, int4, int5 );
    p1( &int2, int5 );
    printf( "int1 %d, int2 %d, int3 %d, int4 %d, int5 %d\n", int1, int2, int3, int4, int5 );
    return 0;
}

void p1( int *x, int y )
{
    static int int2 = 5;
           int int1 = 2;
           
    *x = *x + 3;
    y  =  y - 4;
    int1 *= 2;
    int2 += 5;
    int3 -= 1;
    printf( "int1 %d, int2 %d, int3 %d, *x %d, y %d\n", int1, int2, int3, *x, y );
}