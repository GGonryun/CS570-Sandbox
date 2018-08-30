/*             endofsen.c
 *
 * int endofsen( int * punctptr )
 * PRECONDITION:  punctptr contains the ASCII value of a character 
 *                variable that will contain a found puctuation 
 *                mark.
 *
 * POSTCONDITION: A function that finds the end of a sentence if
 *                it ends in '.', '?', '!'.  Returns 1 for
 *                success, 0 for end-of-file. 
 *
 */

/* Include Files */
#include <stdio.h>

int endofsen( int * punctptr )                         /* Note 1 */
{
    int iochar;
    while ( ( iochar = getchar() ) != EOF )
        if (( iochar == '.' ) || ( iochar == '?' ) || ( iochar == '!' )) {
            *punctptr = iochar;                        /* Note 2 */
            return 1;                                  /* Note 3 */
        }
    return 0;                                          /* Note 4 */
}