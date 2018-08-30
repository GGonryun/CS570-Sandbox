/*             block.c
 *
 * Synopsis  - The values of two variables named i are
 *             displayed. They are declared in two
 *             different blocks.
 *
 * Objective - To illustrate block structuring of C source 
 *             code.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{
    int i = 3;

    {                                                      /* Note 1 */
        int i = 5;                                         /* Note 2 */
                                                           /* Note 3 */
        printf("In the inner block, i is %d.\n", i);
    }
                                                           /* Note 4 */
    printf("In the outer block, i is %d.\n", i);
    return 0;
}
