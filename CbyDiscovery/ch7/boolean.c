/*             boolean.c
 *
 * Synopsis  - Accepts input of a positive integer and
 *             displays all its factors.
 *
 * Objective - Illustrates the use of the enumerated type to
 *             create a variable that takes values TRUE and
 *             FALSE.
 */


/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Type Descriptions */
enum boolean { FALSE, TRUE };                              /* Note 1 */

int main( void )
{
    enum boolean prime;                                    /* Note 2 */
    int num, divisor;
    char inarray[80];

    printf( "Enter a positive integer to be tested: " );
    num = atoi( gets( inarray ) );

    if ( num <= 0 ) {
        printf( "Sorry, that number wasn't positive.\n" );
        exit( 1 );
    }

    prime = TRUE;                                          /* Note 3 */
    printf( "List of divisors: 1 " );

    for ( divisor = 2; divisor < num; divisor++ )
        if ( !( num % divisor ) ) {
            printf( " %d ", divisor );
            prime = FALSE;                                 /* Note 4 */
        }

    if ( num != 1 )
        printf( " %d\n", num );
    else
        prime = FALSE;                                     /* Note 5 */

    if ( prime )                                           /* Note 6 */
        printf( "%d is a prime number\n", num );
    return 0;
}