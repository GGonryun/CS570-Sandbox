/*             automatc.c
 *
 * Synopsis  - Displays two integer values.
 *
 * Objective - Illustrates automatic variables.
 */

/* Include Files */
#include <stdio.h>

/* Function Declarations*/
int increment( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: Increments an automatic local variable and
 *                returns its incremented value.
 */

int main( void )
{
    printf( "%d\n", increment() );                   /* Note 2 */
    printf( "%d\n", increment() );
}

/*******************************increment()*********************/
/*   increment() - Increments an automatic local variable and
 *                 returns its incremented value.
 */
int increment( void )
{
    int number = 0;                                  /* Note 1 */

    return ( ++number );
}