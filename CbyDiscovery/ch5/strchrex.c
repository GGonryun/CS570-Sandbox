/*             strchrex.c
 *
 * Synopsis  - Accepts a line of text as input from standard
 *             input and displays each of the space-delimited
 *             words in the input on a separate line on
 *             standard output.
 *
 * Objective - To illustrate the string library function
 *             strchr().
 */

/* Include Files */
#include <stdio.h>
#include <string.h>

int main( void )
{
    char instring[512];
    char *currentpos, *lastpos;                           /* Note 1 */

    printf( "Enter a line of text.\n> " );
    gets( instring );                                     /* Note 2 */
    lastpos = instring;

                                                          /* Note 3 */
    while ( ( currentpos = strchr( lastpos, ' ' ) ) != NULL ) {
        *currentpos++ = '\0';                             /* Note 4 */
        puts( lastpos );
        lastpos = currentpos;                             /* Note 5 */
    }
    puts( lastpos );
    return 0;
}