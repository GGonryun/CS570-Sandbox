/*             la16.c
 *
 * Synopsis  - Displays the sizeof() a structure and
 *             the values of two pointer arithmetic
 *             expressions.
 *
 * Objective - To provide practice with pointer 
 *             arithmetic with pointers to structures.
 */

/* Include Files */
#include <stdio.h>

/* Type Descriptions */
struct auto_part {
    char id[8];
    double price;
    int cur_inv;
} part;

int main( void )
{
    struct auto_part * partptr = &part;

    printf( "sizeof( part ) %d\n", sizeof( part ) );
    printf( "partptr %d, partptr+1 %d\n", partptr, partptr+1);
    return 0;
}
