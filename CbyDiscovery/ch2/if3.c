/*             if3.c
 * Synopsis  - The program prompts for and accepts input of a
 *             decimal integer.  It then tests to see if that
 *             integer is even or odd.  The results of the
 *             test are displayed.
 *
 * Objective - Illustrates an if-else statement and the use   
 *             of a function call in a control expression.
 */

/* Include Files */
#include <stdio.h>

/* Function Declarations */
int odd(int intvar );
/* PRECONDITION:  intvar can be any integer
 *
 * POSTCONDITION: The value returned is 1 if the parameter is odd
 *                and 0 if the parameter is even
 */

int main(void)
{
    int intvar;

    printf( "Enter a decimal integer: " );
    scanf( "%d", &intvar );

    if ( odd( intvar ) )                                  /* Note 1 */
        printf( "%d is odd.\n", intvar );
    else                                                  /* Note 2 */
        printf( "%d is even.\n", intvar );
    return 0;
}

/******************************* odd() ***************************/

int odd( int intvar )
{
    return( intvar % 2 );                                 /* Note 3 */
}
