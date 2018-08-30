/*             strngerr.c
 *
 * Synopsis  - Initializes two strings and displays the 
 *             strings and their locations. Displays the
 *             strings again after concatenating the
 *             second string to the end of the first one.
 *
 * Objective - To demonstrate a common error in memory 
 *             allocation when using the string library 
 *             functions.
 */

/* Include Files */
#include <stdio.h>
#include <string.h>

int main( void )
{
    char *string1 = "I know an old lady who swallowed a ";
    char *string2 = "spider that wiggled and jiggled and tickled inside her";

    puts( string1 );
    puts( string2 );
                                                        /* Note 1 */
    printf( "\nstring1 begins at %p, and ends at %p.\n", string1, string1 + strlen( string1 ) );
    printf( "string2 begins at %p, and ends at %p.\n\n", string2, string2 + strlen( string2 ) );
                                                        /* Note 2 */
    strcat( string1, " horse.  She's dead of course." );
    puts( string1 );
    puts( string2 );
    return 0;
}