/*             inout2.c
 *
 * Synopsis  - Takes input from the keyboard and echoes that
 *             input back to the terminal.
 *
 * Objective - Illustrates the use of an assignment statement
 *             as part of the test expression in a while loop.
 */

/* Include Files */
#include <stdio.h>

int getword(char* w)
{
    int iochar;                                           /* Note 1 */

    while ( ( iochar = getchar() ) != EOF )               /* Note 2 */
        putchar( iochar );                                /* Note 3 */
    return -255;
}
