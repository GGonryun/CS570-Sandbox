/*             switch2.c
 *
 * Synopsis  - Displays a menu, accepts a choice from a user,
 *             and processes the response.
 *
 * Objective - Illustrates the switch and break statements
 *             together.
 */

/* Include Files */
#include <stdio.h>

/* Function Prototypes */
void processresponse( char iochar );
/* PRECONDITION:  iochar can be any character value.
 *
 * POSTCONDITION: Compares iochar with the case labels and takes 
 *                action accordingly.
 */

int menu( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: Displays the menu choices and accepts input of the 
 *                user's response. The first character of the 
 *                response is returned.
 */

int main( void )
{
    char iochar = 0;

    do {
        iochar = menu();                               /* Note 1 */
        processresponse( iochar );
    }
    while ( iochar != '0' );
    return 0;
}

/******************************* menu() **************************/ 

int menu( void )
{
    char response[40];

    printf( "The following games are available:\n" );
    printf( "----------------------------------\n\n" );
    printf( "1. Guessit\n" );
    printf( "2. Nim\n" );
    printf( "----------\n" );
    printf( "Choose a game or type 0 to exit.\nYour choice?  ");

    if ( gets( response ) == NULL )
        return( '0' );                                 /* Note 1 */
    else
        return( response[0] );                         /* Note 1 */
}

/******************************* processresponse() ***************/

void processresponse( char iochar )
{
    switch ( iochar ) {                                /* Note 2 */
        case '0': break;                               /* Note 3 */
        case '1': printf( "You have chosen guessit.\n" );
                  break;                               /* Note 4 */
        case '2': printf( "You have chosen nim.\n" );
                  break;                               /* Note 4 */
                                                       /* Note 5 */
        default:  printf( "Illegal input.\n" );
                  printf( "Choose 0, 1, or 2.\n" );
    }
}