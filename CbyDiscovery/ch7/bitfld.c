/*             bitfld.c
 *
 * Synopsis  - Declares a structure with bit fields, displays
 *             its size in bytes, initializes the structure
 *             and displays the contents of it.
 *
 * Objective - Provides an example of a structure with
 *             bit fields.
 */

/* Include Files */
#include <stdio.h>
#include <string.h>

/* Type Descriptions */
struct empl {
    char ssn[10];
    float rate;
    char initials[4];
    unsigned vested : 1;
                                                       /* Note 1 */
    unsigned years_of_service : 6;
                                                       /* Note 2 */
};

/* Function Declarations */
void put_empl( struct empl *emp );
/* PRECONDITION:  emp contains the address of a struct empl.
 *
 * POSTCONDITION: Displays the contents of the struct empl passed
 *                as a parameter.
 */

int main( void )
{
    struct empl emp1;

                                                       /* Note 3 */
    printf( "sizeof( struct empl )  %d.\n", sizeof( struct empl ) );

    strcpy( emp1.ssn, "567624256" );
    emp1.rate = 7.50;
    strcpy( emp1.initials, "WLF" );
    emp1.vested = 1;
                                                       /* Note 4 */
    emp1.years_of_service = 17;
    put_empl( &emp1 );
    return 0;
}

/******************************* put_empl() **********************/

void put_empl( struct empl *emp )
{
    printf( "SSN:    %12s\n", emp->ssn );
    printf( "Rate:  $%12.2f\n", emp->rate );
    printf( "Initials%12s\n", emp->initials );
    printf( "vested  %12d\n", emp->vested );

                                                       /* Note 5 */
    printf( "years of service %3d\n", emp->years_of_service );
}