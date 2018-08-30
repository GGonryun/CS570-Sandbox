/*             recurs2.c
 *
 * Synopsis  - Accepts input of a positive integer, calculates
 *             its factorial, and displays the result.
 *
 * Objective - Illustrates the use of conditional compilation
 *             during program development and debugging.
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define DEBUG
/* Directives for Conditional Compilation */
#ifdef DEBUG                                             /* Note 1 */
int nesting = 0;                                         /* Note 2 */
                                                         /* Note 3 */
#define ENTER(fn)  printf("\n%*s{ ENTER %s\n", ++nesting*4, "", fn)
#define EXIT(fn)   printf("\n%*s} EXIT  %s\n", nesting--*4, "", fn)
#else
#define ENTER(fn)                                        /* Note 4 */
#define EXIT(fn)
#endif

/* Constant Declarations */
#define BLANK          ' '
#define END_OF_LINE    '\n'

/* Function Declarations */
long factorial( long n );
/* PRECONDITION:  n is a long
 *
 * POSTCONDITION: uses a recursive algorithm to calculate the 
 *                factorial of its argument
 */

long convert( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: reads standard input until either a BLANK, an 
 *                END_OF_LINE or a nondigit is found; if only digits 
 *                are found, the function returns the converted 
 *                value as type int; otherwise, the function error() 
 *                is called
 */

void error( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: displays an error message and terminates the 
 *                program with exit value 1
 */

int main( void )
{
    long n;
    ENTER("main");                                       /* Note 5 */
    printf( "Program to Calculate Factorials.\n" );
    printf( "------- -- --------- -----------\n" );
    printf( "\nEnter a positive integer value : " );

    n = convert();                                       /* Note 2 */

    printf( "\n%ld! is %ld.\n", n, factorial( n ) );
    EXIT( "main" );                                      /* Note 7 */
    return 0;
}

/******************************* factorial() *********************/

long factorial( long n )
{
    long temp;

    ENTER( "factorial" );
    if ( n == 0 ) {
        EXIT( "factorial - 1" );                         /* Note 3 */
        return ( 1 );
    }
    else {
        temp = n * factorial( n - 1 );
        EXIT( "factorial" );                             /* Note 7 */
        return ( temp ); 
    }
}

/******************************* convert() ***********************/

long convert( void )
{
    int ch;
    long sum = 0;

    ENTER( "convert" );
    while ((( ch = getchar() ) != BLANK ) && (ch != END_OF_LINE )) {
        if ( !isdigit( ch ) )
            error();
        sum = sum * 10 + ( ch - '0' );
    }
#ifdef DEBUG                                             /* Note 6 */
    printf( "Converted Value: %ld\n", sum );
#endif

    EXIT( "convert" );                                   /* Note 7 */
    return ( sum );
}

/******************************* error() *************************/

void error( void )
{
    ENTER( "error" );
    printf( "Nondigit in input. Program terminated.\n" );
    EXIT( "Terminating Program" );                       /* Note 7 */
    exit( 1 );
}