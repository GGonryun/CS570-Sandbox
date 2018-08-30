/*             malloc.c
 *
 * Synopsis  - Accepts input of a line of text, separates each 
 *             of the blank-separated words in the line, and
 *             displays each word.
 *
 * Objective - To illustrate use of the malloc() function.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>                                         /* Note 1 */
#include <string.h>

int main( void )
{
    char instring[512], *currentpl, *endword, *word;

    printf( "Enter a line of text " );
    printf( "with words separated with blanks:\n" );
    gets( instring );
    currentpl = instring;
                                                            /* Note 2 */
    while (( endword = strchr( currentpl, ' ' )) != NULL ) {
        *endword = '\0';                                    /* Note 3 */
                                                            /* Note 4 */
        word = ( char * ) malloc( strlen( currentpl ) + 1 );
        strcpy( word, currentpl );
        printf( "I read that as \"%s\".\n", word );
        currentpl = endword+1;                              /* Note 5 */
        free (( void * ) word );                            /* Note 6 */
    }
                                                            /* Note 7 */
    word = ( char * )malloc( strlen( currentpl ) + 1 );
    strcpy( word, currentpl );
    printf( "I read that as \"%s\".\n", word );
    free(( void * ) word );
    return 0;
}
