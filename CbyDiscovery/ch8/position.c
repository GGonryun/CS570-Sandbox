/*             position.c
 *
 * Synopsis  - Program calls endofsen() to read input up to 
 *             the first occurrence of '.', '?', or '!' and 
 *             then calls a stub function (that needs to be 
 *             completed) to process the remaining input.
 *
 * Objective - To illustrate calling of a function for the 
 *             tasks it performs and not for its return value
 *             or its parameter value.
 */

/* Include Files */
#include <stdio.h>

/* Function Prototypes */
extern int endofsen( int *punctptr );
/* See Example 8-12 for precondition and postcondition information.
 */

void processinput( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: A stub function. It reads to end of input. 
 */

int main( void )
{
    int dummy;

    printf( "Enter your input now.  Terminate by " );
    printf( "signaling end of file.\n" );

    endofsen( &dummy );                              /* Note 1 */

    processinput();
    return 0;
}

/*******************************processinput()******************/

void processinput( void )
{
    int iochar;

    while (( iochar = getchar() ) != EOF ) {         /* Note 2 */
        /* code for processing would go here */
    }
}