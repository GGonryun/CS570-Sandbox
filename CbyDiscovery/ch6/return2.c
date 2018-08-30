/*             return2.c
 *
 * Synopsis  - Positions input stream to the character after
 *             '#' or after the end of the input line.
 *
 * Objective - To illustrate a return statement with an
 *             expression.
 */

/* Include Files */
#include <stdio.h>

/* Constant Declarations */
#define END_OF_LINE '\n'
#define DELIMITER   '#'
/* Function Prototypes */
int look_for_delimiter( char delimiter, char end_of_line );
/* PRECONDITION:  delimiter and end_of_line can be any character 
 *                variables.
 *
 * POSTCONDITION: Reads a line of input and compares each character 
 *                to delimiter. Returns 1 when delimiter is found, 
 *                and 0 otherwise.
 */

int main( void )
{
    int found;

    printf( "Enter a line of text with a '#'.\n> " );
    found = look_for_delimiter( DELIMITER, END_OF_LINE );        /* Note 1 */
    if ( found )                                                 /* Note 2 */
        printf( "found a %c.\n", DELIMITER );
    else
        printf( "read until end of line.\n" );
    return 0;
}

/******************************* look_for_delimiter() ************/

int look_for_delimiter( char delimiter, char end_of_line )
{
    int iochar;

    while ( ( iochar = getchar() ) != END_OF_LINE ) {
        if ( iochar == DELIMITER )
            return 1;                                            /* Note 3 */
    }                                                            /* Note 4 */
    return 0;
}