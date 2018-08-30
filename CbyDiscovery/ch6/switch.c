/*             switch.c
 *
 * Synopsis  - Displays a triangle of numbers.
 *
 * Objective - To illustrate the syntax and flow of control
 *             of the switch statement.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{
    int test_value;

    printf( "Enter an integer between 0 and 9: " );
    scanf( "%d", &test_value );
    switch ( test_value ) {                                  /* Note 1 */
        case 9:    printf( "9 9 9 9 9 9 9 9 9\n" );          /* Note 2 */
        case 8:    printf( " 8 8 8 8 8 8 8 8\n" );
        case 7:    printf( "  7 7 7 7 7 7 7\n" );
        case 6:    printf( "   6 6 6 6 6 6\n" );
        case 5:    printf( "    5 5 5 5 5\n" );
        case 4:    printf( "     4 4 4 4\n" );
        case 3:    printf( "      3 3 3\n" );
        case 2:    printf( "       2 2\n" );
        case 1:    printf( "        1\n" );
        case 0:    printf( "00000000000000000\n" );          /* Note 3 */
        default :  printf( "-----------------\n" );
    }
    return 0;
}