/*             stackex.c
 *
 * Synopsis  - A driver program to test the stack utilities. 
 *             This program accepts a line of input from 
 *             standard input and displays the characters 
 *             in reverse order to standard output.
 *
 * Objective - To demonstrate and test the stack utilities.
 */

/* Include Files */
#include <stdio.h>
#include "stack.h"                                    /* Note 1 */

int main( void )
{
    char inbuff[80];
    int index;
    STACK st;                                         /* Note 2 */

    printf( "Enter a line of characters : " );
    gets( inbuff );

    init_stack( &st );                                /* Note 3 */
    for ( index = 0; inbuff[index] != '\0'; index++ ) {
        push( inbuff[index], &st );
    }

    while ( !is_empty( st ) ) {
        putchar( pop( &st ) );
    }
    putchar( '\n' );
    return 0;
}