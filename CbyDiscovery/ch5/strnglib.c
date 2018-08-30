/*             strnglib.c
 *
 * Synopsis  - Displays information about two strings, 
 *             the length, and their lexical comparison. Then
 *             concatenates them into a character buffer and
 *             displays the result.
 *
 * Objective - To illustrate basic use of the string library
 *             functions, strlen(), strcat(), strcpy(), and
 *             strcmp().
 */

/* Include Files */
#include <stdio.h>
#include <string.h>                                      /* Note 1 */

int main( void )
{
    char workstring[512];                                /* Note 2 */
    char *string1 = "I know an old lady";
    char *string2 = "who swallowed a fly";

    puts( string1 );
    puts( string2 );
    if ( strcmp( string1, string2 ) > 0 )                /* Note 3 */
        printf( "string1 is > string2.\n" );
    else
        printf( "string1 is <= string2.\n" );

                                                         /* Note 4 */
    printf( "The length of string1 is %d.\n", strlen( string1 ) );
    printf( "The length of string2 is %d.\n", strlen( string2 ) );

    strcpy( workstring, string1 );                       /* Note 5 */
    if ( !strcmp( string1, workstring ) )                /* Note 6 */
        printf( "Copy completed successfully!\n" );
    else
        printf( "Error found in copy.\n" );

    strcat( workstring, " " );                           /* Note 7 */
    strcat( workstring, string2 );
    printf( "The work string now contains:\n\t\"%s\"\n", workstring );
    printf( "The length of the work string is now %d.\n", strlen( workstring ) );
    return 0;
}