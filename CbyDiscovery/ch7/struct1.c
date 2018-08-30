/*             struct1.c
 *
 * Synopsis  - Accepts input of an auto_part from standard
 *             input and echoes it to standard output.
 *
 * Objective - To illustrate a pointer to a structure and 
 *             passing a pointer to a structure and a 
 *             structure as parameters to a function. 
 */

/* Include Files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Constant Declarations */
#define GOT_ONE	     1                                  /* Note 1 */
#define NONE_ENTERED 0
#define IDSIZE       8

/* Type descriptions */
struct auto_part {
                                                        /* Note 2 */
    char id[8];
    double price;
    int cur_inv;
};

/* Function Declarations */
void put_part( struct auto_part part );
                                                        /* Note 3 */
/* PRECONDITION:  part is a struct auto_part.
 *
 * POSTCONDITION: Displays the contents of the struct auto_part 
 *                passed as a parameter.
 */

int get_part( struct auto_part *partptr );
                                                        /* Note 4 */
/* PRECONDITION:  partptr contains the address of a struct auto_part.
 *
 * POSTCONDITION: Populates the struct auto_part, whose address is 
 *                contained in the parameter, with information read 
 *                from the keyboard then returns 1 if data was 
 *                entered by the user and 0 if no data was entered.
 */
int main( void )
{
    struct auto_part part;
                                                       /* Note 5 */
    int retval;

    retval = get_part( &part );
                                                       /* Note 6 */
    if ( retval == GOT_ONE )
        put_part( part );
    return 0;
}

/******************************* get_part() **********************/

int get_part( struct auto_part *partptr )              /* Note 4 */
{
    char instring[512];

    printf( "Enter the part number :" );
    gets( instring );
    if ( strlen( instring ) > 0 ) {
        strncpy( partptr->id, instring, 7);
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

void put_part( struct auto_part part )                 /* Note 3 */
{
    printf( "Part-id:  %8s\n", part.id );              /* Note 7 */
    printf( "Price :  $%8.2f\n", part.price );         /* Note 7 */
    printf( "Quantity: %8d\n", part.cur_inv );         /* Note 7 */
}