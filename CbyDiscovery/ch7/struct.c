/*             struct.c
 *
 * Synopsis  - Declares and initializes a variable of type 
 *             struct auto_part and displays its contents 
 *             on the terminal screen. 
 *
 * Objective - To illustrate declaring a structure and
 *             accessing its members.
 */
/* Include Files */
#include <stdio.h>


/* Type Descriptions */
struct auto_part {                              /* Note 1 */
    char id[8];
    double price;
    int cur_inv;
};

int main( void )
{
							
                                                /* Note 2 */
    struct auto_part part = { "J-145D", 4.79, 12 };

    printf( "Part-id:  %8s\n", part.id );
                                                /* Note 3 */
    printf( "Price :  $%8.2f\n", part.price );
                                                /* Note 3 */
    printf( "Quantity: %8d\n", part.cur_inv );
                                                /* Note 3 */
    return 0;
}