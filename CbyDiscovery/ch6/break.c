/*             break.c
 *
 * Synopsis  - Accepts input of a line of text and displays
 *             the part of a line before the SENTINEL
 *             character.
 *
 * Objective - To illustrate the break statement.
 */

/* Include Files */
#include <stdio.h>

/* Constant Declarations */
#define EOLN     '\n'
#define SENTINEL '#'

/* Function Prototypes */
void readtosentinel( char eoln, char sentinel );
/* PRECONDITION:  eoln and sentinel are character variables 
 *                containing the end of line character and the 
 *                sentinel value respectively.
 *
 * POSTCONDITION: Reads a line of text from standard input. Stops 
 *                when either sentinel is encountered or eoln is 
 *                read. 
 */
int main( void )
{
    printf( "The sentinel character is %c.\n", SENTINEL );
    printf( "Enter a line with a sentinel in it.\n\n" );

    readtosentinel( EOLN, SENTINEL );

    printf( "\n\nThat was the first part of the line.\n" );
    return 0;
}

/******************************* readtosentinel() ****************/

void readtosentinel( char eoln, char sentinel )
{
    int iochar;

    while ( ( iochar = getchar() ) != eoln ) {
        if ( iochar == sentinel ) {
            break;                                     /* Note 1 */
        }
        putchar( iochar );
    }
}