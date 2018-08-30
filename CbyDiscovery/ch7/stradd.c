/*             stradd.c
 *
 * Synopsis  - Displays the sizeof() a structure and the
 *             addresses of two structure variables and
 *             their members.
 *
 * Objective - To demonstrate the layout of a structure
 *             in memory.
 */

/* Include files */
#include <stdio.h>

/* Type Descriptions */
struct empl {
                                                      /* Note 1 */
    char ssn[10];
    char initials[5];
    float rate;
    float hours;
};

int main ( void )
{
    struct empl employee1, employee2;
                                                      /* Note 2 */
    printf( "sizeof(struct empl) is %d.\n", sizeof( struct empl ) );
    printf( "employee1 is located at %p.\n", &employee1 );
    printf( "employee2 is located at %p.\n", &employee2 );
    printf( "\nIn employee1,\n" );
                                                      /* Note 3 */
    printf( "\tssn is at %p.\n", &employee1.ssn );
    printf( "\tinitials is at %p.\n", &employee1.initials );
    printf( "\trate is at %p.\n", &employee1.rate );
    printf( "\thours is at %p.\n", &employee1.hours );

    printf( "\nIn employee2, \n" );
    printf( "\tssn is at %p.\n", &employee2.ssn );
    printf( "\tinitials is at %p.\n", &employee2.initials );
    printf( "\trate is at %p.\n", &employee2.rate );
    printf( "\thours is at %p.\n", &employee2.hours );
    return 0;
}