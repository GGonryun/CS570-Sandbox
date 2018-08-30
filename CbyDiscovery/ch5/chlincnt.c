/*             chlincnt.c
 *
 * Synopsis  - Counts the number of characters and lines
 *             in standard input.
 *
 * Objective - Illustrates a use for strlen() in conjunction
 *             with gets().
 */

/* Include Files */
#include <stdio.h>
#include <string.h>

int main( void )
{
    char inarray[512];                                /* Note 1 */
    char *inptr;
    int line_count = 0,                               /* Note 2 */
        char_count = 0;

    printf( "Enter your text now." );
    printf( "Signal end-of-file when done.\n" );
    printf( "> " );
                                                      /* Note 3 */
    while ( ( inptr = gets( inarray ) ) != NULL ) {
        line_count++;                                 /* Note 4 */
        char_count += strlen( inptr ) + 1;    /* Note 5 */
        printf( "> " );
    }
    printf( "\n%d lines, %d characters\n", line_count, char_count );
    return 0;
}