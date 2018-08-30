/*             ctype.c
 *
 * Synopsis  - Counts the number of alphabetics, digits,
 *             whitespace, punctuation and control characters
 *             in its input. The input can come from a file
 *             or the keyboard.
 *
 * Objective - To illustrate the use of the functions defined
 *             in ctype.h.
 */
/* Include Files */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>                                       /* Note 1 */

int main( int argc, char *argv[] )
{
    FILE *fp;
    int ch;
    int numlower = 0, numupper = 0, numdigit = 0,
        numspace = 0, numcntrl = 0, numalpha = 0,
        numpunct = 0;

    if ( argc < 2 )
        fp = stdin;                                      /* Note 2 */
        else if (( fp = fopen( argv[1], "r" )) == NULL ) {
            printf( "Can't open file %s.\n", argv[1] );
            exit( 1 );
        }

    while (( ch = getc( fp )) != EOF ) {
        if ( isalpha( ch ))  {                           /* Note 3 */
            numalpha++;
            if ( islower( ch ))                          /* Note 4 */
                numlower++;
            else
                numupper++;                              /* Note 5 */
        }
        else if ( isdigit( ch ))                         /* Note 6 */
            numdigit++;
        else if ( isspace( ch ))                         /* Note 7 */
            numspace++;
        else if ( ispunct( ch ))                         /* Note 8 */
            numpunct++;
        else if ( iscntrl( ch ))                         /* Note 9 */
            numcntrl++;
    }
    printf( "\nThat data contained %d alphabetic characters ", numalpha );
    printf( "of which %d were uppercase \n", numupper );
    printf( "and %d were lowercase.  It also contained ", numlower );
    printf( "%d digits, %d whitespace", numdigit, numspace );
    printf( " characters,\n%d control characters, ", numcntrl );
    printf( "and %d punctuation characters.\n", numpunct );
    return 0;
}