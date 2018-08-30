/*             enumindx.c
 *
 * Synopsis  - Accepts input of the number sold of each color
 *             of an item, stores the number in an array and
 *             displays the contents of the array.
 *
 * Objective - Illustrates the use of enum types for indexing
 *             an array and the underlying connection between
 *             enum types and ints.
 */

/* Include Files */
#include <stdio.h>
#include <string.h>

/* Type Descriptions */
enum color { jade, navy, white, coral, maize };         /* Note 1 */

/* Function Declarations*/
void makestring( enum color, char *string );            /* Note 2 */
/* PRECONDITION:  string contains the address of a character array 
 *                which must be declared by the calling function.
 *
 * POSTCONDITION: Creates a string containing the color currently
 *                contained in item_color. Used to aid output.
 */

void print_sales( int sales[] );
/* PRECONDITION:  sales[] in an array of integers.
 *
 * POSTCONDITION: Will display the color and contents of each cell 
 *                of sales[]. Uses the integer representation of the 
 *                colors.
 */

void get_sales( int *salesrecord );
/* PRECONDITION:  salesrecord contains the address of an array of ints 
 *                which must be declared by the calling function.
 *
 * POSTCONDITION: Accepts input of the number sold of each color 
 *                item from standard input. Uses the identifier form 
 *                of the color.
 */

int main( void )
{
    int salesrecord[5];

    get_sales( salesrecord );
    print_sales( salesrecord );
    return 0;
}

/******************************* makestring() ********************/

                                                        /* Note 3 */
void makestring( enum color item_color, char *string )
{
    switch ( item_color ) {                             /* Note 4 */
        case jade:  strcpy( string, "jade" );
                    break;
        case navy:  strcpy( string, "navy" );
                    break;
        case white: strcpy( string, "white" );
                    break;
        case coral: strcpy( string, "coral" );
                    break;
        case maize: strcpy( string, "maize" );
    }
}

/******************************* print_sales() *******************/

void print_sales( int sales[] )
{
    int i;
    char colorstr[6];

    printf( "The sales record shows the following " );
    printf( "sales by color.\n" );

    for( i = 0; i < 5; i++ ) {
        makestring( i, colorstr );                      /* Note 5 */
        printf( "%5s : %d\n", colorstr, sales[i] );
    }
}

/******************************* get_sales() *********************/

void get_sales( int *salesrecord )
{
    enum color d_color;
    char colorstr[6];

    printf( "Enter the number of each color sold:\n" );

                                                        /* Note 6 */
    for ( d_color = jade; d_color <= maize; d_color++ ) {
        makestring( d_color, colorstr );                /* Note 7 */
        printf( "%5s : ", colorstr );
                                                        /* Note 8 */
        scanf( "%d", &salesrecord[d_color] );
    }
}