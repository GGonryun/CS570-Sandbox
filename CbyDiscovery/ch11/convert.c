/*             convert.c
 *
 * Synopsis  - Accepts the input of a string of digits and
 *             converts those digits to a decimal integer.
 *
 * Objective - To show the use of the facility isdigit() in
 *             validating input.
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h>                                       /* Note 1 */

int main( void )
{
    int index = 0, num = 0;
    char inbuff[80];

    printf( "Enter a string of decimal digits: " );
    gets( inbuff );

    while ( isdigit( inbuff[index] ))                    /* Note 2 */
                                                         /* Note 3 */
    num = 10*num + inbuff[index++] - '0';

    printf( "That number is %d.\n", num );
    return 0;
}