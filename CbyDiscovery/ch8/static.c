/*             static.c
 *
 * Synopsis  - Outputs two integer values.
 *
 * Objective - Illustrates static variables.
 */

/* Include Files */
#include <stdio.h>

/* Function Declarations */
int increment( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: Increments a static local variable and
 *                returns its incremented value.
 *
 */

int main( void )
{
    printf( "%d\n", increment() );                   /* Note 2 */
    printf( "%d\n", increment() );
}

/*******************************increment()*********************/

int increment( void )
{
    static int number = 0;                           /* Note 1 */

    return ( ++number );
}