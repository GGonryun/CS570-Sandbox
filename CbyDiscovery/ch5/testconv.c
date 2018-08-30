/*             testconv.c
 *
 * Synopsis  - Inputs lines with gets() and passes 
 *             the string to conv(). Displays the 
 *             value returned by conv() and the 
 *             remainder of the string.
 *
 * Objective - To provide a test program for the 
 *             user-written function to convert a 
 *             string of digits to type int.
 */
	
/* Include Files */
#include <stdio.h>
#include <string.h>
	
/* Function Declarations */
int conv( char [], char ** );
/* Fill in your PRECONDITION and POSTCONDITION here. */
	
int main( void )
{
    int intval;
    char array[80], *remainder;

    while ( gets( array ) != NULL ) {
        intval = conv( array, &remainder );
        printf( " %d, %s\n", intval, remainder );
    }
    return 0;
}
