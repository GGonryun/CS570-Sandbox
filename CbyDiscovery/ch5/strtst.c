/*             strtst.c
 *
 * Synopsis  - Calls strstr() twice to find 
 *             substrings in "how now brown cow".
 *             One should be found, the other is
 *             nonexistent.
 *
 * Objective - To provide a test program for 
 *             personal version of strstr().
 */
	
/* Include Files */
#include <stdio.h>
#include <string.h>

int main( void )
{
    char string[] = "How now brown cow";
    char *substring;

    substring = strstr( string, "own" );
    if ( substring == NULL )
        printf( "Not found.\n" );
    else
        printf( "%s\n", substring );

    substring = strstr( string, "red" );
    if ( substring == NULL )
        printf( "Not found.\n" );
    else
        printf( "%s\n", substring );
    return 0;
}
