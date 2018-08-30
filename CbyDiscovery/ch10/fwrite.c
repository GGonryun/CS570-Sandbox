/*             fwrite.c
 *
 * Synopsis  - Accepts input of information about banking
 *             transactions and stores the information in
 *             a file.
 *
 * Objective - To illustrate the use of fwrite() to do block
 *             output of a structure.
 */

/* Include Files */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* Constant Declarations */
#define TRUE      1
#define FALSE     0
#define BUFFSIZE  50

/* Type Descriptions */
struct trans {                                      /* Note 1 */
    int t_type;
    char payee_memo[BUFFSIZE];
    double amount;
    unsigned tax_deduct:1;
    unsigned cleared:1;
};

/* Function Prototypes */
int get_type( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: Requests and accepts input of the transaction type 
 *                from the keyboard. Returns a check number for a 
 *                check, the ASCII value of a D for a deposit, the 
 *                ASCII value of a W for a withdrawal or the ASCII 
 *                value of a Q for quit.
 */

void get_trans( struct trans *trans_ptr );
/* PRECONDITION:  The parameter trans_ptr contains the address of a 
 *                struct trans declared by the calling function.
 *
 * POSTCONDITION: Takes input from the termianl to populate the 
 *                struct trans pointed to by the passed parameter.
 */

void put_trans( struct trans *trans_ptr, FILE *fp );
/* PRECONDITION:  The parameter trans_ptr contains the address of a 
 *                struct trans declared by the calling function. fp
 *                contains the address of a FILE *.
 *
 * POSTCONDITION: Writes the contents of the structure pointed to by
 *                trans_ptr to the file associated with fp.
 */

int main( void )
{
    struct trans transact;
    FILE *fp;
                                                    /* Note 2 */
    if (( fp = fopen( "transact", "a+" )) == NULL ) {
        printf( "Transaction file couldn't be opened.\n" );
        exit( 1 );
    }

    /*  The following while loop will continue until the
     *  user types a 'Q' for the transaction type.  Each
     *  time the loop is executed, one transaction is input
     *  and stored in the file.
     */
    while (( transact.t_type = get_type() ) != 'Q' ) {
        get_trans( &transact );
        put_trans( &transact, fp );
    }
    fclose( fp );
    return 0;
}

/*******************************gettype()***********************/

int get_type( void )
{
    char buffer[80];
    int correct = FALSE, t_type;

    while ( !correct ) {
        printf( "D=deposit, W=withdrawal, or Check #\n" );
        printf( "Enter transaction type ('Q' to quit): " );
        gets( buffer );
        if ( isdigit( *buffer )) {
	    /* convert string of digits to
             * type int
             */
            correct = TRUE;
            t_type = atoi( buffer );
        }
        else {
            /* Translate any alphabetic character
             * to uppercase for testing and storage.
             */
            t_type = toupper( ( int ) *buffer );
            if (( t_type !='D' )&& ( t_type !='W' ) && ( t_type != 'Q' ))
                printf( "Incorrect, try again\n" );
            else
                correct = TRUE;
        }
    }
	return( t_type );
}

/*******************************get_trans()*********************/

void get_trans( struct trans *trans_ptr )
{
    char inbuf[80];

    printf( "Amount: $" );
    trans_ptr->amount = atof( gets( inbuf ));

    switch ( trans_ptr->t_type ) {
        case 'W':
        case 'D': printf( "Memo: " );
                  fgets( trans_ptr->payee_memo,BUFFSIZE, stdin );
                  break;
        default:  printf( "Payee: " );
                  fgets( trans_ptr->payee_memo,BUFFSIZE, stdin );
    }

    printf( "Tax_deductible? (y/n) : " );
    gets( inbuf );
    if (( *inbuf == 'y' ) || ( *inbuf == 'Y' ))
        trans_ptr->tax_deduct = 1;
    else
        trans_ptr->tax_deduct = 0;

    printf( "Cleared? (y/n) : " );
    gets( inbuf );
    if (( *inbuf == 'y' ) || ( *inbuf == 'Y' ))
        trans_ptr->cleared = 1;
    else
        trans_ptr->cleared = 0;
}

/*******************************put_trans()*********************/

void put_trans( struct trans *trans_ptr, FILE *fp )
{
                                                     /* Note 3 */
    fwrite( trans_ptr, sizeof( struct trans ), 1, fp );
}