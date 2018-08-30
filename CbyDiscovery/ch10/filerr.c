/*             filerr.c
 *
 * Synopsis  - Attempts to make a copy of a file.  Designed to be
 *             invoked with the file names on the command line.
 *
 * Objective - To illustrate the need for storing the return 
 *             value from getchar() in a variable of type int.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
    FILE *fpin, *fpout;
    unsigned char iochar;

    if ( argc != 3 ) {
        printf( "Usage: cp oldfile newfile\n" );
        exit( 1 );
    }

    if (( fpin = fopen( argv[1], "r" )) == NULL ) {
        printf( "Can't open input file.\n" );
        exit( 1 );
    }

    if (( fpout = fopen( argv[2], "w" )) == NULL ) {
        printf( "Can't open output file.\n" );
        exit( 1 );
    }

    while (( iochar = getc( fpin )) != EOF )          /* Note 1 */
        putc( iochar, fpout );

    fclose( fpin );
    fclose( fpout );
    return 0;
}