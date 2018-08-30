/*             unions.c
 *
 * Synopsis  - Accepts input of and displays information for 
 *             one employee.
 *
 * Objective - To demonstrate use of enum types to keep track
 *             of the contents of a union.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Type Descriptions */
enum paytype { hourly, salaried };                     /* Note 1 */

union rate {                                           /* Note 2 */
    double per_hour;
    int   per_week;
};

struct employee {
    char  name[20];
    char  ssn[12];
    enum  paytype paytype;                             /* Note 3 */
    union rate payrate;
};

/* Function Prototypes */
void reademp( struct employee *emptr );
/* PRECONDITION:  emptr contains the address of a struct employee.
 *
 * POSTCONDITION: Accepts input information from the keyboard and 
 *                stores it in a struct employee.
 */

void printemp( struct employee emp );
/* PRECONDITION:  emp is a struct employee.
 *
 * POSTCONDITION: Displays the contents of the struct employee 
 *                parameter.
 */

int main( void )
{
    struct employee emp;

    reademp( &emp );
    printemp( emp );
    return 0;
}

/******************************* reademp() ***********************/

void reademp( struct employee *emptr )
{
    char instring[80];

    printf( "Enter the information for an employee.\n" );
    printf( "Name : " );
    gets( emptr->name );
    printf( "Social Security Number: " );
    gets( emptr->ssn );
    printf( "Hourly or salaried (h or s) : " );
    gets( instring );

                                                       /* Note 4 */
    if ( ( *instring == 'h' ) || ( *instring == 'H' ) )
        emptr->paytype = hourly;
    else if ( ( *instring == 's' ) || ( *instring == 'S' ) )
        emptr->paytype = salaried;
    else {
        printf( "Illegal paytype, program terminated.\n" );
        exit( 1 );                                     /* Note 5 */
	}
    if ( emptr->paytype == hourly ) {                  /* Note 6 */
        printf( "Enter the hourly rate: " );
        emptr->payrate.per_hour = atof( gets(instring) );
    }
    else {
        printf( "Enter the weekly salary: " );
        emptr->payrate.per_week = atoi( gets(instring) );
    }
}

/******************************* printemp() **********************/

void printemp( struct employee emp )
{
    printf( "Name :   %s\n", emp.name );
    printf( "Social Sec. No. : %s\n", emp.ssn );
    if ( emp.paytype == hourly )                       /* Note 7 */
        printf( "Hourly rate   :$%7.2f\n", emp.payrate.per_hour );
    else
        printf( "Weekly Salary :$%7d\n", emp.payrate.per_week);
}