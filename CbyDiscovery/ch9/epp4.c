/*             epp4.c
 *
 * Synopsis  - Accepts input of 6 stock prices into a
 *             two-dimensional array and should output 
 *             the percent change from the old prices. 
 *             Has a syntax error.
 *
 * Objective - To provide practice with the C syntax and 
 *             the relationship between different 
 *             expressions.
 */
	
/* Include Files */
#include <stdio.h>
#include <stdlib.h>
	
/* Global Variables */
double stock_prices[2][6] = { { 12, 80, 30,
                                100, 40, 50  } };

/* Function Prototypes */
/* Add PRECONDITION and POSTCONDITION information for 
 * each function
 */
void output_change( double *new, double *old );
void input_prices( void );
	
int main( void )
{
    printf( "STOCK INFORMATION PROGRAM\n");
    printf( "-------------------------\n");
    printf( "This program will give information about the " );
    printf( "prices of \nsix specific stocks. You are to " );
    printf( "enter the current prices of \nthe stocks. The ");
    printf( "percent change from the buying prices\n" );
    printf( "will be displayed.\n\n" );

    input_prices();
    output_change( *stock_prices, *( stock_prices+1 ));
    return 0;
}

/***********************input_prices()**************/
/* Accepts input of 6 quantities of type float to be 
 * stored in the second "row" of the array. The 
 * combination of library functions gets() and atof() is 
 * used to input the float value.
 */
	
void input_prices( void )
{
    int i;
    char instring[20];

    printf( "Please enter the current stock prices now.\n" );
    printf( "Stock\tBuying price\tCurrent price\n" );
    printf( "-----\t------------\t-------------\n" );
    for ( i = 0; i < 6; i++ ) {
        printf( "#%d: \t%6.2f   \t  ", i+1, stock_prices[0][i] );
        stock_prices[1][i] = atof( gets( instring ));
    }
    printf( "Thank you!\n" );
}
	
/***********************output_change()*************/
/* Outputs the percentage change of the new prices in
 * comparison with the old.
 */
void output_change( double *old, double *new )
{
    double change;
    int i;

    printf( "\nPercent change of each stock:\n" );
    for ( i = 0; i < 6; i++ ) {
        printf( "Stock #%d: ", i );

        /* Calculate the percent change */
	change = ( *new++ / *old++ - 1 ) * 100; 
        printf( "Percent change is %3.0f%%.\n", change );
    }
}