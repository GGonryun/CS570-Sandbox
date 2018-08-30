/*             cmdline.c
 *
 * Synopsis  - Prints the value of argc and the command
 *             line parameters.
 *
 * Objective - To illustrate how command line parameters work
 *             and to demonstrate two techniques for accessing
 *             the arguments passed to a program on the command
 *             line.
 */

/* Include Files */
#include <stdio.h>

int main( int argc, char *argv[] )                        /* Note 1 */
{
    int index ;

    printf( "There were %d arguments on the command line.\n",argc );
    printf( "They are :\n" );

    for ( index = 0; index < argc; index++ )              /* Note 2 */
        printf( "\t%p \t%s\n", argv[index], argv[index] );
    printf( "\n\n" );
                                                          /* Note 3 */
    printf( "Terminating char * value in argv, %p\n", argv[argc] );
    printf( "\n" );

    while ( argc-- > 0 )                                  /* Note 4 */
        printf( "   %s ", *argv++ );
    printf( "\n\n" );
    return 0;
}