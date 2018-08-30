/*             cp.c
 *
 * Synopsis  - Makes a copy of a file. The names for the original
 *             file and the copy are on the command line.
 *
 * Objective - To illustrate file handling.
 */

/* Include Files */
#include <stdio.h>                                  /* Note 1 */
#include <stdlib.h>

int main( int argc, char *argv[] )
{
    FILE *fpin, *fpout;                             /* Note 2 */
    int iochar;

    if ( argc != 3 ) {
        printf( "Usage: cp oldfile newfile\n" );
        exit( 1 );                                  /* Note 3 */
    }

    if (( fpin = fopen( argv[1], "r" )) == NULL ) {
                                                    /* Note 4 */
        printf( "Can't open input file.\n" );
        exit( 1 );
    }

    if (( fpout = fopen( argv[2], "w" )) == NULL ) {
                                                    /* Note 5 */
        printf( "Can't open output file.\n" );
        exit( 1 );
    }

    while (( iochar = getc( fpin )) != EOF )        /* Note 6 */
        putc( iochar, fpout );

    fclose( fpin );
    fclose( fpout );
    return 0;
}