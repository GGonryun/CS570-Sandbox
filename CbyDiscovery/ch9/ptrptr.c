/*             ptrptr.c
 *
 * Synopsis  - Outputs information, strings, and individual
 *             characters in an array of pointers to type char.
 *
 * Objective - To illustrate double indirection and use the
 *             pointer to a pointer to traverse an array of
 *             pointers.
 */

/* Include Files */
#include <stdio.h>
#include <string.h>


int main( void )
{
    char *ptrarray[] =  { "George",
                          "Elliot's",
                          "Oldest",
                          "Girl",
                          "Rode",
                          "A",
                          "Pig",
                          "Home",
                          "Yesterday",
                          ""                        /* Note 1 */
                        };

    char **ptrptr = ptrarray;                       /* Note 2 */

                                                    /* Note 3 */
    printf( "sizeof( ptrarray )  %d,\tsizeof( ptrptr )  %d\n", sizeof( ptrarray ), sizeof( ptrptr ));
    printf( "ptrarray          %p,\tptrptr         %p\n", ptrarray, ptrptr );
    printf( "ptrarray[0]       %p,\t*ptrptr        %p\n\n", ptrarray[0], *ptrptr );

                                                    /* Note 4 */
    printf( "ptrarray[0]   %s,\t*ptrptr       %s\n", ptrarray[0], *ptrptr );
    printf( "ptrarray[1]   %s,\t*( ptrptr+1 ) %s\n\n", ptrarray[1], *( ptrptr+1 ));

                                                    /* Note 5 */
    printf( "*ptrarray[0]       %c,\t**ptrarray       %c\n", *ptrarray[0], **ptrarray );
    printf( "ptrarray[0][4]     %c,\t*(*ptrarray + 4) %c\n\n", ptrarray[0][4], *( *ptrarray+4 ));

                                                    /* Note 6 */
    for (  ; strcmp( *ptrptr, ""); ptrptr++ )
        printf( "%s ", *ptrptr );
    printf( "\n" );
                                                    /* Note 7 */
    for ( ptrptr = ptrarray; strcmp( *ptrptr, "" ); ptrptr++ )
        printf( "%c", **ptrptr );
    printf( "\n" );
    return 0;
}