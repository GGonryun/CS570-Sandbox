/*             return1.c
 *
 * Synopsis  - Positions input stream to either the character
 *             after '#' or at the end of the input line.
 *
 * Objective - To illustrate the simplest form of the
 *             return statement.
 */

/* Include Files */
#include <stdio.h>

/* Constant Declarations */
#define END_OF_LINE  '\n'
#define DELIMITER    '#'

/* Function Prototypes */
void look_for_delimiter( char delimiter, char end_of_line );
/* PRECONDITION:  delimiter and end_of_line can be any character 
 *                variables.
 *
 * POSTCONDITION: Reads a line of text, character by character. 
 *                Returns when delimiter is found in the input.
 */

int main( void )
{
                                                       /* Note 1 */
    printf( "Enter a line of text with a %c.\n> ", DELIMITER );
    look_for_delimiter( DELIMITER, END_OF_LINE );
    printf( "Done looking!\n" );                       /* Note 1 */
    return 0;
}

/******************************* look_for_delimiter() ************/

void look_for_delimiter( char delimiter, char end_of_line )
{
    int iochar;

    while ( ( iochar = getchar() ) != end_of_line ) {
        if ( iochar == delimiter )
        return;                                        /* Note 2 */
    }
    printf( "At end of line\n" );                      /* Note 3 */
}