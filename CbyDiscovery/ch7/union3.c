/*             union3.c
 *
 * Synopsis  - Declares and initializes a union and displays 
 *             information about its addresses and contents.
 *
 * Objective - To illustrate the properties of memory
 *             allocation with unions.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{

    union x {                                          /* Note 1 */
        int intmem;
        float floatmem;
        unsigned bitmem:4;
        char stringmem[20];
    } tryit;

    tryit.intmem = 0x1248;                             /* Note 2 */
                                                       /* Note 3 */
    printf( "Sizeof the union and its members.\n" );
    printf( "---------------------------------\n" );
    printf( "sizeof(union x)  %d\n", sizeof( union x ) );
    printf( "sizeof(tryit.intmem) %d\n", sizeof(tryit.intmem));
    printf( "sizeof(tryit.floatmem) %d\n", sizeof( tryit.floatmem ));
    printf( "sizeof(tryit.bitmem) %d\n", sizeof( tryit.bitmem ));
    printf( "sizeof(tryit.stringmem) %d\n\n", sizeof( tryit.stringmem ));
                                                       /* Note 4 */
    printf( "Addresses of the union and the members.\n" );
    printf( "---------------------------------------\n" );
    printf( "&tryit  %x.\n", &tryit );
    printf( "&tryit.intmem  %x\n", &(tryit.intmem) );
    printf( "&tryit.floatmem %x\n", &(tryit.floatmem) );
    printf( "&tryit.bitmem %x\n", &tryit.bitmem );
    printf( "tryit.stringmem  %x.\n\n", tryit.stringmem );
                                                       /* Note 5 */
    printf( "Contents of members of the union.\n" );
    printf( "---------------------------------\n" );
    printf( "intmem = %x.\n", tryit.intmem );
    printf( "tryit.floatmem %5.2f\n", tryit.floatmem );
    printf( "tryit.bitmem %x\n", tryit.bitmem );
    printf( "tryit.stringmem[0] %x\n", tryit.stringmem[0] );
    printf( "tryit.stringmem[1] %x\n", tryit.stringmem[1] );
    printf( "tryit.stringmem[2] %x\n\n", tryit.stringmem[2] );
    return 0;
}