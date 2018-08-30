/*             continue.c
 *
 * Synopsis  - Echoes its input to its output with each tab
 *             character replaced with '\t'.
 *
 * Objective - To illustrate the continue statement.
 */

/* Include Files */
#include <stdio.h>

/* Function Prototypes */
void showtabsinline( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: Reads and echoes a line of text from standard 
 *                input. Every tab character in the input is replaced 
 *                by the two characters '\' and 't'.
 */

int main( void )
{
    printf( "Enter a line with tab characters in it.\n\n" );
    showtabsinline();
    return 0;
}

/******************************* showtabsinline() ****************/

void showtabsinline( void )
{
    int iochar;

    while ( ( iochar = getchar() ) != '\n' ) {
        if ( iochar == '\t' ) {
            putchar( '\\' );
            putchar( 't' );
            continue;                                  /* Note 1 */
        }
        putchar( iochar );                             /* Note 2 */
    }
    putchar( '\n' );
}