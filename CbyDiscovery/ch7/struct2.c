/*             struct2.c
 *
 * Synopsis  - Initializes an array of structures with input 
 *             from the terminal and displays the total 
 *             inventory on standard output.
 *
 * Objective - To illustrate arrays of structures, pointers to
 *             structures, and passing structures to functions.
 */
/* Include Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constant Declarations */
#define GOT_ONE      1
#define NONE_ENTERED 0
#define ID_SIZE      8
#define MAXPARTS     4

/* Type Descriptions */
struct auto_part {
    char id[ID_SIZE];
    double price;
    int cur_inv;
};

/* Function Declarations */
int get_part( struct auto_part *partptr );
/* PRECONDITION:  partptr contains the address of a struct auto_part.
 *
 * POSTCONDITION: Populates the struct auto_part, whose address is 
 *                contained in the parameter, with information read 
 *                from the keyboard then returns 1 if data was 
 *                entered by the user and 0 if no data was entered.
 */
void put_part( struct auto_part part );
/* PRECONDITION:  part is a struct auto_part.
 *
 * POSTCONDITION: Displays the contents of the struct auto_part 
 *                passed as a parameter.
 */

int main( void )
{
    struct auto_part parts[MAXPARTS];
                                                        /* Note 1 */
    int j, num_parts = 0;

    printf( "Initializing Inventory\n" );
    printf( "------------ ---------\n\n" );


                                                        /* Note 2 */
    while ( get_part( parts+num_parts ) && ++num_parts < MAXPARTS )
    ;
    if ( num_parts == MAXPARTS )
                                                        /* Note 3 */
        printf( "Inventory full\n" );

    printf( "\n\nPrinting Inventory of Auto Parts\n" );
    printf( "-------- --------- -- ---- -----\n\n" );
    for ( j = 0; j < num_parts; j++ )
        put_part( parts[j] );
    return 0;
}
/******************************* get_part() **********************/

int get_part( struct auto_part *partptr )
{
    char instring[512];

    printf( "Enter the part number :" );
    gets( instring );
    if ( strlen( instring ) > 0 ) {

        strncpy( partptr->id, instring, ID_SIZE-1 );
        partptr->id[7] = '\0';

        printf( "Enter the price: " );
        partptr->price = atof( gets( instring ) );

        printf( "Enter the amount in inventory : " );
        partptr->cur_inv = atoi( gets( instring ) );
        return( GOT_ONE );
    }
    else
        return( NONE_ENTERED );
}

/******************************* put_part() **********************/

void put_part( struct auto_part part )
{
    printf( "Part-id:  %8s\n", part.id );
    printf( "Price :  $%8.2f\n", part.price );
    printf( "Quantity: %8d\n", part.cur_inv );
}