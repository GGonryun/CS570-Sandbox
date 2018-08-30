/*             fread.c
 *
 * Synopsis  - Reads transactions (elements of type struct 
 *             trans) from a file and displays them on 
 *             standard output.
 *
 * Objective - To illustrate the use of fread() with structures.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Constant Declarations */
#define BUFFSIZE  50

/* Type Descriptions */
struct trans {
    int t_type;
    char payee_memo[BUFFSIZE];
    float amount;
    unsigned tax_deduct:1;
    unsigned cleared:1;
};

/* Function Prototypes */
void print_trans( struct trans *outtrans );
/* PRECONDITION:  The parameter outtrans contains the address of a 
 *                struct trans declared by the calling function.
 *
 * POSTCONDITION: Displays the contents of the structure pointed to 
 *                by outtrans on standard output. Each field is 
 *                separated with a vertical bar character.
 */

int read_trans( struct trans *trans_ptr, FILE *fp );
/* PRECONDITION:  The parameter trans_ptr contains the address of a 
 *                struct trans declared by the calling function. fp
 *                contains the address of a FILE *.
 *
 * POSTCONDITION: Reads a single transaction from the file 
 *                associated with fp and stores it in the structure 
 *                pointed to by trans_ptr.
 */

int main( void )
{
    struct trans transact;
    FILE *fp;

    if (( fp = fopen( "transact", "r" )) == NULL ) {
        printf( "Transaction file couldn't be opened.\n" );
        exit( 1 );
    }

    while ( read_trans( &transact, fp ))             /* Note 1 */
        print_trans( &transact );
    fclose( fp );
    return 0;
}

/*******************************read_trans()********************/

int read_trans( struct trans *trans_ptr, FILE *fp )
{
    int retval;
                                                     /* Note 2 */
    retval = fread( trans_ptr, sizeof( *trans_ptr ), 1, fp );
    return ( retval );
}

/*******************************print_trans()*******************/

void print_trans( struct trans *outtrans )
{
    /* Cleared field */
    if ( outtrans->cleared )
        printf( "C | " );
    else
        printf( "  | " );

    /* Transaction type */
    if (( outtrans->t_type =='D' ) || ( outtrans->t_type == 'W' ) || ( outtrans->t_type == 'I' ))
        printf( "%4c | ", outtrans->t_type );
    else
        printf( "%4d | ", outtrans->t_type );

    /* tax_deduct field */
    if ( outtrans->tax_deduct )
        printf( " T | " );
    else
        printf( "   | " );

    printf( "%10.2f  | ", outtrans->amount );
    printf( "%s", outtrans->payee_memo );
}
