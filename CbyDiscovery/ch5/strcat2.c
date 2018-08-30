/*             strcat2.c
 *
 * char *strcat( char *old, char *new )
 * PRECONDITION:  new is a null terminated string. old is an array of
 *                characters containing a null terminated string, with 
 *                enough space at the end to contain new.
 *
 * POSTCONDITION: Concatenates new to the end of old. 
 */

char *strcat( char *old, char *new )
{
    char *current = old;

    while ( *current++ != '\0' )                           /* Note 1 */
    ;

    current--;                                             /* Note 2 */
    while ( *current++ = *new++ )
    ;
    return( old );
}
