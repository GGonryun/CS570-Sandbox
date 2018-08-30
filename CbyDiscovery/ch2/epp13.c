/*             epp13.c
*/

/* Include Files */
#include <stdio.h>

int main( void )
{
    int i, count = 0;

    for ( i = 8; i >= 0; i-- ) {
        if ( !( i%4 ) || ( i--%3 ) ) {
            i--;
            count++;
        }
    }
	
    printf( "%d\n", count );               /*___________________*/

    printf( "%d\n", count && ++i );        /*___________________*/

    printf( "%d\n", !count );              /*___________________*/

    printf( "%d\n", i > 0 );               /*___________________*/

    printf( "%d\n", 0 < count < 3 );       /*___________________*/
    return 0;
}
