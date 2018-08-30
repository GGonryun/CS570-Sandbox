/*             global.c
 *
 * Synopsis  - Assigns values to some variables and displays 
 *					those values.
 *
 * Objective - Illustrates the difference between global and 
*              local variables
*/

/* Include Files */
#include <stdio.h>

/* Global Variables */
int globalvar;                                       /* Note 1 */
int same_name = 3;                                   /* Note 1 */

/* Function Declarations */
void sub_fcn( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: Assigns values to local and global variables and 
 *                displays the values.
 *
 */

int main( void )
{
    int localvar;                                    /* Note 2 */

    globalvar = 2;                                   /* Note 3 */
    localvar = 3;                                    /* Note 4 */
    printf( "Starting in main, " );
    printf( "globalvar is %d, localvar is %d.\n", globalvar, localvar );

    sub_fcn();

    printf( "\nAfter returning to main, " );
                                                     /* Note 9 */
    printf( "globalvar is %d, localvar is %d,\n", globalvar, localvar );
    printf( "and same_name has value %d.\n", same_name );
    return 0;
}

/*******************************sub_fcn()***********************/

void sub_fcn( void )
{
    int localvar;                                    /* Note 5 */
    int same_name;                                   /* Note 6 */

    globalvar = 4;                                   /* Note 7 */
    localvar = 5;                                    /* Note 8 */
    same_name = 127;
    printf( "\nIn sub_fcn, " );
    printf( "globalvar is %d, localvar is %d,\n", globalvar, localvar );
    printf( "and same_name has value %d.\n", same_name );
}