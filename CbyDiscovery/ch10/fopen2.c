/*             fopen2.c
 *
 * Synopsis  - Opens a file named info and closes it.
 *
 * Objective - Demonstrates elementary error handling with
 *             fopen() and fclose().
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
FILE *fp;
                                                    /* Note 1 */
    if (( fp = fopen( "info", "r" )) == NULL ) {
        printf( "Input file could not be opened\n" );
        exit( 1 );
    }

    /* Other code to process the file might
     * be placed here.
     */

    if ( fclose( fp ) == EOF )                      /* Note 2 */
        printf( "File couldn't be closed\n" );
    return 0;
}