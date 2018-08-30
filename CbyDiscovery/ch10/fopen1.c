/*             fopen1.c
 *
 * Synopsis  - Opens a file for reading and then closes it.
 *
 * Objective - To present the most basic file handling.
 */

/* Include Files */
#include <stdio.h>                                     /* Note 1 */

int main( void )
{
    FILE *fp;                                          /* Note 2 */

    fp = fopen( "info", "r" );                         /* Note 3 */

    /* Other code to process the file might
     * be placed here.
     */

    fclose( fp );                                      /* Note 4 */
    return 0;
}