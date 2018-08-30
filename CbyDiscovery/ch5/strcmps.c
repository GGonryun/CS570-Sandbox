/*             strcmps.c
 *
 * Synopsis  - Outputs the values returned by library 
 *             function strcmp().
 *
 * Objective - To investigate the return value from 
 *             strcmp().
 */
	
/* Include Files */
#include <stdio.h>
#include <string.h>

int main( void )
{
    char string1[80];
    char string2[80];
    int result;

    printf( "Enter the first string: " );
    gets( string1 );
    printf( "Enter the second string: " );
    gets( string2 );

    if ( ( result = strcmp( string1, string2 ) ) > 0 )
        printf( "string1 > string2\n" );
    else if ( result < 0 )
        printf( "string1 < string2\n" );
    else
        printf( "string1 = string2\n" );

    printf( "result is %d\n", result );
    return 0;
}
