/*             ptrarray.c
 *
 * Synopsis  - Accepts a line of text as input from the key- 
 *             board. Finds the individual words in the input
 *             text, counts them, displays the count, and 
 *             displays the words in reverse order.
 *
 * Objective - Illustrates use of an array of pointers to char.
 */

/* Include Files */
#include <stdio.h>
#include <string.h>

int main( void )
{
    char instring[512];
    char *words[50],                                       /* Note 1 */
         *current;
    int  i = 1;

    printf( "Enter text with words delimited by blanks:\n" );
    gets( instring );

    words[0] = current = instring;                         /* Note 2 */
                                                           /* Note 3 */
    while ( ( current = strchr( current, ' ' )) != NULL ) {
        *current++ = '\0';
        words[i++] = current;                              /* Note 4 */
    }

    printf( "There were %d words in that line.\n", i );
    printf( "In reverse order they are :\n" );
    for ( --i; i >= 0; i-- )
        printf( "%s\n", words[i] );                        /* Note 5 */
    return 0;
}