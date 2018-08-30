/*             ccomp.c
 *
 * Synopsis  - Accepts input of information about a customer 
 *             from standard input, and stores the information
 *             in a file named "statements".
 *
 * Objective - To illustrate conditional compilation.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Type Descriptions */
struct statement {
    char name[30];
#ifdef ACME                                               /* Note 1 */
    char account[9];
#else
    char account[17];
#endif
    float balance;
    struct {
#ifdef ACME                                               /* Note 2 */
        char t_code[5];
#else
        int t_code;
#endif
        int quantity;
        float price;
    } transactions[50];
};

/* Function Declarations */
int get_customer( struct statement *cust );
/* PRECONDITION:  cust is a pointer to a struct statement declared
 *                in the calling function
 *
 * POSTCONDITION: accepts input of information for a single customer
 */

int main( void )
{
    struct statement customer;
    FILE *fp;

    if (( fp = fopen( "statements", "w" )) == NULL ) {
        perror( "File Opening Error" );
        exit( 1 );
    }

    printf( "Enter your customer transactions now.\n" );
    printf( "Signal EOF when you are done.\n" );

    while ( get_customer( &customer ))
        fwrite( &customer, sizeof( customer ), 1, fp );

    printf( "Thank you, the statements will be prepared.\n" );
    return 0;
}

/******************************* get_customer() ******************/

int get_customer( struct statement *cust )
{
    printf( "Enter customer name: " );
    if ( fgets( cust->name, 30, stdin ) == NULL )
        return ( 0 );

    printf( "Enter customer account number: " );
#ifdef ACME                                              /* Note 3 */
    fgets( cust->account, 8, stdin );
#else
    fgets( cust->account, 16, stdin );
#endif

    /* code to enter the transactions goes here */
    return ( 1 );
}