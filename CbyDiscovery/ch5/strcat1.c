/*                strcat1.c
 *
 * char *strcat( char old[], char new[] )
 * PRECONDITION:  new is a null terminated string. old is an array of
 *                characters containing a null terminated string, with 
 *                enough space at the end to contain new.
 *
 * POSTCONDITION: Concatenates new to the end of old. 
 */

char *strcat( char old[], char new[] )
{
    int oldindex = 0,
        newindex = 0;

    while ( old[oldindex++] != '\0' )                      /* Note 1 */
    ;

    oldindex--;                                            /* Note 2 */
    while ( ( old[oldindex++] = new[newindex++] ) != '\0' )
    ;
    return( old );
}