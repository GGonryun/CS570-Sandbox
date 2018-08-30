/*             ungetc.c
 *
 * Synopsis  - Picks out all strings of alphabetic characters
 *             and all strings of digits from "text" and prints
 *             each on a separate line of terminal output.
 *
 * Objective - Illustrates the use of the file facilities
 *             ungetc(), feof() and the character typing 
 *             facilities isalpha() and isdigit().
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h>                                     /* Note 1 */
#include <stdlib.h>

int main( void )
{
    FILE *fp;
    int iochar;

    if (( fp = fopen( "text", "r" )) == NULL ) {
        printf( "text couldn't be opened\n" );
        exit( 1 );
    }

    while ( !feof( fp )) {                             /* Note 2 */
                                                       /* Note 3 */
        while ( isalpha( iochar = getc( fp )))
            putchar( iochar );
        putchar( '\n' );
        ungetc( iochar, fp );                          /* Note 4 */
                                                       /* Note 5 */
        while ( isdigit( iochar = getc( fp )))
        putchar( iochar );
        putchar( '\n' );
        ungetc( iochar, fp );                          /* Note 6 */
                                                       /* Note 7 */
        while ( !isalpha( iochar = getc( fp )) &&
              ( !isdigit( iochar )) &&
              ( !feof( fp )))
        ;
        ungetc( iochar, fp );                          /* Note 8 */
    }
    fclose( fp );
    return 0;
}