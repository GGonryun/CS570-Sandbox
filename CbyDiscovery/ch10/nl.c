/*            nl.c
 *
 * Synopsis - Opens a text file and copies the lines of the
 *            file to standard output with each text line
 *            preceded by a line number.
 *
 * Objective - To illustrate the use of fgets() for input and
 *             fputs() for output.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Constant Declarations */
#define NUMCHARS 512

int main( int argc, char *argv[] )
{
    char inarray[NUMCHARS];                               /* Note 1 */
    int linecount = 1;
    FILE *fp;

    if ( argc < 2 ) {
        printf( "Usage:  nl  filename\n" );
        exit( 1 );
    }
    else if (( fp = fopen( argv[1], "r" )) == NULL ) {
        printf( "Unable to open file %s.\n", argv[1] );
        exit( 1 );
    }
                                                          /* Note 2 */
    while ( fgets( inarray, NUMCHARS, fp ) != NULL ) {
        printf( "%d\t", linecount++ );
        fputs( inarray, stdout );                         /* Note 3 */
    }
    fclose( fp );
    return 0;
}