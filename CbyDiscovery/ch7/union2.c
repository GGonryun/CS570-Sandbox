/*             union2.c
 *
 * Synopsis  - Displays the values of the bits and the bytes 
 *             in a short int.
 *
 * Objective - To illustrate the use of bit fields and unions
 *             in accessing the bits and bytes of a quantity.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{
    struct bits {                                          /* Note 1 */
        unsigned first     :1;
        unsigned second    :1;
        unsigned third     :1;
        unsigned fourth    :1;
        unsigned fifth     :1;
        unsigned sixth     :1;
        unsigned seventh   :1;
        unsigned eighth    :1;
        unsigned ninth     :1;
        unsigned tenth     :1;
        unsigned eleventh  :1;
        unsigned twelfth   :1;
        unsigned thirteenth:1;
        unsigned fourteenth:1;
        unsigned fifteenth :1;
        unsigned sixteenth :1;
    } ;

    struct bytes {                                        /* Note 2 */
        unsigned first :8;
        unsigned second:8;
    } ;

    union access {                                        /* Note 3 */
        short whole;
        struct bits bit_access;
        struct bytes byte_access;
    } testvar;

                                                          /* Note 4 */
    printf( "sizeof(struct bits)  %d.\n", sizeof( struct bits ) );
    printf( "sizeof(struct bytes) %d.\n", sizeof( struct bytes ) );
    printf( "sizeof(union access) %d.\n\n", sizeof(union access) );

    testvar.whole = 0x1248;                               /* Note 5 */

                                                          /* Note 6 */
    printf( "first byte %x, second byte %x.\n\n", testvar.byte_access.first, testvar.byte_access.second );
                                                          /* Note 7 */
    printf( "Bits:\tfirst       %x,  second      %x,\n", testvar.bit_access.first, testvar.bit_access.second );
    printf( "\tthird       %x,  fourth      %x,\n", testvar.bit_access.third, testvar.bit_access.fourth );
    printf( "\tfifth       %x,  sixth       %x,\n", testvar.bit_access.fifth, testvar.bit_access.sixth );
    printf( "\tseventh     %x,  eighth      %x,\n", testvar.bit_access.seventh, testvar.bit_access.eighth );
    printf( "\tninth       %x,  tenth       %x,\n", testvar.bit_access.ninth, testvar.bit_access.tenth );
    printf( "\televenth    %x,  twelfth     %x,\n", testvar.bit_access.eleventh, testvar.bit_access.twelfth );
    printf( "\tthirteenth  %x,  fourteenth  %x,\n", testvar.bit_access.thirteenth, testvar.bit_access.fourteenth );
    printf( "\tfifteenth   %x,  sixteenth   %x\n", testvar.bit_access.fifteenth, testvar.bit_access.sixteenth );
    return 0;
}