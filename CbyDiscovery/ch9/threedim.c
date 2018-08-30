/*             threedim.c
 *
 * Synopsis  - Displays the contents of a three-dimensional 
 *             array as a pair of two-dimensional arrays.
 *
 * Objective - Illustrates declaration, initialization, and
 *             element access in a three-dimensional array.
 */

/* Include Files */
#include <stdio.h>

int main( void )
{                                                        /* Note 1 */
    double three_d[2][3][4] = {                          /* Note 2 */
                                 {  { 0.0, 0.1, 0.2, 0.3 },
                                    { 1.0, 1.1, 1.2, 1.3 },
                                    { 2.0, 2.1, 2.2, 2.3 }
                                 },
                                 {  { 10.0, 10.1, 10.2, 10.3 },
                                    { 11.0, 11.1, 11.2, 11.3 },
                                    { 12.0, 12.1, 12.2, 12.3 }
                                 }
                              };
    int i, j, k;

    for ( i = 0; i < 2; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            for ( k = 0; k < 4; k++ ) {                  /* Note 3 */
                printf( "%5.1f\t", three_d[i][j][k] );
            }
            printf( "\n" );
        }
        printf( "\n\n" );
    }
    return 0;
}