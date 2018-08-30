/*             strngio2.c
 *
 * Synopsis  - Prompts for and accepts a line of text as input
 *             from standard input with the standard library
 *             function gets(). Echoes the line to standard
 *             output with puts().
 *
 * Objective - To illustrate gets() and puts().
 */

/* Include Files */
#include <stdio.h>                              /* Note 1 */

int main( void )
{
    char inputarray[512];                       /* Note 2 */
    char *inputptr;

    printf( "Enter a line of text.\n> " );
    inputptr = gets( inputarray );              /* Note 3 */
    if ( inputptr != NULL )                     /* Note 4 */
        puts( inputptr );                       /* Note 5 */
    else
        puts( "error in input\n" );             /* Note 6 */
    return 0;
}