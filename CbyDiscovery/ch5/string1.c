/*             string1.c
 *
 * Synopsis  - Displays a string, address of a string and
 *             some characters from the string.
 *
 * Objective - To illustrate how C compilers handle strings.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{
        char *stringptr;                            /* Note 1 */

        stringptr = "Testing, 1, 2, 3\n";           /* Note 2 */

        printf( stringptr );                        /* Note 3 */
        printf( "%s", stringptr );                  /* Note 4 */
        printf( "%p\n", stringptr );                /* Note 5 */

                                                    /* Note 6 */
        printf( "First Character: %c\n", stringptr[0] );
                                                    /* Note 7 */
        printf( "Second Character: %c\n", *( stringptr + 1 ) );
        return 0;
}
