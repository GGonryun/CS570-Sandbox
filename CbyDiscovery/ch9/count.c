/*             count.c
 *
 * Synopsis  - Takes values of initial, final, and step from 
 *             the command line arguments. Counts from the 
 *             low value of initial to the high value of
 *             final with increments of step.
 *
 * Objective - To illustrate a use of command line arguments.
 *             Also uses the library function atoi().
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void count( char **args );                           /* Note 3 */
/* PRECONDITION:  args contains the address of an array of pointers 
 *                to characters, namely argv[].
 *
 * POSTCONDITION: Displays integer values from argv[1] to argv[2] 
 *                in increments of argv[3].
 */

int main( int argc, char *argv[] )
{
    if ( argc != 4 ) {                               /* Note 1 */
        printf("Usage: count start stop step\n");
        exit(1);
    }
                                                     /* Note 2 */
    printf("Counting from %s to %s by %s's.\n", *(argv+1), *(argv+2), *(argv+3) );
    count( argv );
    return 0;
}
/*******************************count()*************************/

void count( char **args )                            /* Note 3 */
{
    int result, initial, final, step;

    initial = atoi( args[1] );                       /* Note 4 */
    final   = atoi( args[2] );
    step    = atoi( args[3] );

    for ( result = initial; result <= final; result += step )
        printf( "%d\t", result );
    printf("\n");
}