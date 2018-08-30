/*             bitfld2.c
 *
 * Synopsis  - Displays the values of the bits and the bytes
 *					in a short int.
 *
 * Objective - To illustrate the use of bit fields in
 *             accessing the bits and bytes of a quantity.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{
    struct bits {
                                                    /* Note 1 */
        unsigned first : 1;
        unsigned second : 1;
        unsigned third : 1;
        unsigned fourth : 1;
        unsigned fifth : 1;
        unsigned sixth : 1;
        unsigned seventh : 1;
        unsigned eighth : 1;
        unsigned ninth : 1;
        unsigned tenth : 1;
        unsigned eleventh : 1;
        unsigned twelfth : 1;
        unsigned thirteenth : 1;
        unsigned fourteenth : 1;
        unsigned fifteenth : 1;
        unsigned sixteenth : 1;
    } *bit_access;

    struct bytes {
                                                    /* Note 2 */
        unsigned first:8;
        unsigned second :8;
    } *byte_access;

    unsigned short twobytes;
                                                    /* Note 3 */

                                                    /* Note 4 */
    printf( "sizeof( struct bits )  %d.\n", sizeof( struct bits ) );
    printf( "sizeof( struct bytes ) %d.\n", sizeof( struct bytes ));
    printf( "sizeof( twobytes )     %d.\n\n", sizeof( twobytes ) );

    twobytes = 0x1248;
                                                    /* Note 5 */
    byte_access = ( struct bytes * ) &twobytes;						
                                                    /* Note 6 */
    bit_access  = ( struct bits * )  &twobytes;

                                                    /* Note 7 */
    printf( "first byte %x, second byte %x.\n\n", byte_access->first, byte_access->second );

                                                    /* Note 8 */
    printf( "Bits:\tfirst       %x,  second      %x,\n", bit_access->first, bit_access->second);
    printf( "\tthird       %x,  fourth      %x,\n", bit_access->third, bit_access->fourth );
    printf( "\tfifth       %x,  sixth       %x,\n", bit_access->fifth, bit_access->sixth );
    printf( "\tseventh     %x,  eighth      %x,\n", bit_access->seventh, bit_access->eighth );
    printf( "\tninth       %x,  tenth       %x,\n", bit_access->ninth, bit_access->tenth );
    printf( "\televenth    %x,  twelfth     %x,\n", bit_access->eleventh, bit_access->twelfth );
    printf( "\tthirteenth  %x,  fourteenth  %x,\n", bit_access->thirteenth, bit_access->fourteenth );
    printf( "\tfifteenth   %x,  sixteenth   %x\n", bit_access->fifteenth, bit_access->sixteenth );
    return 0;
}