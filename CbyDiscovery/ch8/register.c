/*             register.c
 *
 * Synopsis  - Displays two integer values.
 *
 * Objective - Illustrates register variables.
 */

/* Include Files */
#include <stdio.h>

/* Function Declarations */
int increment_a_lot( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: Increments a register local variable 1000 times and
 *                returns the incremented value.
 *
 */

int main( void )
{
    printf( "%d\n", increment_a_lot() );
    printf( "%d\n", increment_a_lot() );
    return 0;
}

/*******************************increment_a_lot()*****************/

int increment_a_lot( void )
{
    register int number = 0;                           /* Note 1 */

    for ( ; number < 1000; number++ )                  /* Note 2 */
    ;
    return ( number );
}