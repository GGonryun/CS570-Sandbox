/*             output.c
*/

/* Include Files */
#include <stdio.h>                            /* Note 1 */

/* External Variable Declarations */
extern int x;                                 /* Note 2 */

void output( void )
{
    printf( "The value of x is %d.\n", x );
}