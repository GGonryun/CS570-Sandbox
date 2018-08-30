/*             error.c
 *
 * Synopsis  - This code contains compile time errors. Its 
 *             intent is purposely vague.
 *
 * Objective - To illustrate the compiler's understanding of 
 *             local variables and their scope.
 */

/* Include Files */
#include <stdio.h>

/* Function Declarations */
int addit( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: Attempts to add sum to counter. Has syntax errors.
 *
 */

int main( void )
{
    int counter;                                          /* Note 1 */

    for ( counter = 1; counter < 5; counter++ ) {
        int i;                                            /* Note 2 */
        i = counter;                                      /* Note 3 */
        i = i + 5;
        addit();
    }
                                                          /* Note 4 */
    printf( "i was %d; addit() returned %d.\n", i, addit() );
    return 0;
}

/*******************************addit()*************************/

int addit( void )
{
    int sum = 0;                                          /* Note 5 */

    sum = sum + counter;                                  /* Note 6 */
    return ( sum );
}