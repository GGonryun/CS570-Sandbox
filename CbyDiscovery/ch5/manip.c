/*             manip.c
 *
 * Synopsis  - Displays a string and its address. Changes the
 *             string and displays it again.
 *
 * Objective - To illustrate how an array can be used to store
 *             and manipulate a string.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{
                                                     /* Note 1 */
    char work_string[ 512 ] = "One two, buckle my shoe\n";

                                                     /* Note 2 */
    printf( work_string );
    printf( "%s", work_string );
    printf( "%p\n", work_string );

    *( work_string + 7 ) = '\n';                     /* Note 3 */
    work_string[ 8 ] = '\0';                         /* Note 4 */

    printf( work_string );
    return 0;
}