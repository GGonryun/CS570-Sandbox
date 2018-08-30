/*             getpart.c
 *
 * int get_part( struct auto_part *partptr )
 * PRECONDITION:  partptr contains the address of a struct auto_part.
 *
 * POSTCONDITION: Populates the struct auto_part, whose address is 
 *                contained in the parameter, with information read 
 *                from the keyboard then returns 1 if data was 
 *                entered by the user and 0 if no data was entered.
 */

/* Include Files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Constant Declarations */
                                                       /* Note 1 */
#define GOT_ONE      1
#define NONE_ENTERED 0
#define ID_SIZE      8

/* Type Descriptions */
struct auto_part {
    char id[ID_SIZE];
    double price;
    int cur_inv;
};

int get_part( struct auto_part *partptr )
                                                       /* Note 2 */
{
    char instring[512];
    printf( "Enter the part number :" );
    gets( instring );
    if ( strlen( instring ) > 0 ) {
                                                       /* Note 3 */

                                                       /* Note 4 */
        strncpy( partptr->id, instring, ID_SIZE-1 );
        partptr->id[7] = '\0';
                                                       /* Note 5 */

        printf( "Enter the price: " );
                                                       /* Note 6 */
        partptr->price = atof( gets( instring ) );

        printf( "Enter the amount in inventory : " );

                                                       /* Note 7 */
        partptr->cur_inv = atoi( gets( instring ) );
        return( GOT_ONE );
    }
    else
        return( NONE_ENTERED );
}