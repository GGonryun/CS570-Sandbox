
/*             perror.c
 *
 * Synopsis  - Checks for the correct number of command line
 *             parameters, opens the file in argv[1], reads
 *             through the file and reports on any errors found.
 *
 * Objective - To demonstrate the use of some of the error
 *             handling functions.
 */

/* Include Files */
#include <stdio.h>                                       /* Note 1 */
#include <stdlib.h>

/* Function Prototypes */
void processit( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: processit() is a stub function
 */

int main( int argc, char *argv[] )
{
    FILE  *fp;
    char  buf[100];

    if ( argc < 2 ) {
        printf( "Usage: perror file\n" );
        exit( 1 );
    }

    if (( fp = fopen( argv[1], "r" )) == NULL ) {
        perror( "fopen error" );                         /* Note 2 */
    }

    while ( fread( buf, sizeof( char ), 100, fp ) > 0 ) {
        processit();
    }
    if ( ferror( fp )) {                                 /* Note 3 */
        perror( argv[1] );                               /* Note 4 */
        clearerr( fp );                                  /* Note 5 */
    }

    /* Processing may continue */
    return 0;
}

/******************************* processit()************************/

void processit( void )
{
    printf( "File processing stub.\n" );
}
