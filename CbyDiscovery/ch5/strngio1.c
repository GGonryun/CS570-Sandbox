/*             strngio1.c
 *
 * Synopsis  - Accepts a line of text as input from the
 *             keyboard and echoes it to the terminal screen.
 *
 * Objective - To illustrate the use of an array to create a 
 *             string and point out the connection among 
 *             pointers, arrays, and strings.
 */

/* Include Files */
#include <stdio.h>

/* Function Declarations */
void inputstring( char * inputptr );                 /* Note 1 */
/* PRECONDITION: inputptr contains the address of an array of 
*                characters, of sufficient length to hold a line
*                of text entered from the keyboard.
*
* POSTCONDITION: Accepts input of a line of text from the keyboard 
*                and stores it in the array pointed to by its argument.
*/

int main( void )
{
    char inputarray[512];                            /* Note 2 */
    char *inputptr = inputarray;

    printf( "Enter a line of text.\n> " );
    inputstring( inputptr );                         /* Note 3 */
    printf( inputarray );
    return 0;
}

/*******************************inputstring()*******************/

void inputstring( char *inputptr )
{
                                                     /* Note 4 */
    while ( ( *inputptr++ = getchar() ) != '\n' )
    ;

    *( --inputptr ) = '\0';                          /* Note 5 */
}