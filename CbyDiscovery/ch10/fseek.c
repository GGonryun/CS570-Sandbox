/*             fseek.c
 *
 * Synopsis  - Opens a file and displays records at a user's
 *					request.
 * Objective - To introduce the standard library functions 
 *             fseek() and ftell().
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Constant Declarations */
#define BUFFSIZE  50

/* Type Declarations */
struct trans {
    int t_type;
    char payee_memo[BUFFSIZE];
    double amount;
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

void browse( FILE *fp, long numrecs );
/* PRECONDITION:  fp contains the address of a FILE *. numrecs 
 *                contains the number of records.
 *
 * POSTCONDITION: Accepts input of record numbers, finds and 
 *                displays the records until the user signals quit 
 *                with a 'Q'.
 */

int read_trans( struct trans * trans_ptr, FILE * fp);
/* PRECONDITION:  The parameter trans_ptr contains the address of a 
 *                struct trans declared by the calling function. fp
 *                contains the address of a FILE *.
 *
 * POSTCONDITION: Reads a single transaction from the file 
 *                associated with fp and stores it in the structure 
 *                pointed to by trans_ptr.
 */

long int getnumrecs( FILE *fp );
/* PRECONDITION:  fp contains the address of a FILE *. 
 *
 * POSTCONDITION: Calculates the number of records in the file by 
 *                getting the total length of the file and dividing 
 *                by the number of bytes in a record.
 */

int main( void )
{
    FILE *fp;
    long int totalrec;
                                                     /* Note 1 */
    if (( fp = fopen( "transact", "r+" )) == NULL ) {
        printf( "Transaction file couldn't be opened.\n" );
        exit( 1 );
    }
    totalrec = getnumrecs( fp );
    if ( totalrec == -1L ) {
        fprintf( stderr, "Error with transaction file\n" );
        exit( 1 );
    }

    printf( "Transaction Browser\n" );
    printf( "Enter the record number you want to see " );
    printf( "or 'Q' to quit.\n" );
    browse( fp, totalrec );
}

/*******************************read_trans()********************/
                                                     /* Note 2 */
int read_trans( struct trans * trans_ptr, FILE * fp)
{
    int retval;

    retval = fread( trans_ptr, sizeof( *trans_ptr ), 1, fp );
    return ( retval );
}

/*******************************print_trans()*******************/

void print_trans( struct trans *outtrans )           /* Note 3 */
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

/*******************************browse()************************/

void browse( FILE *fp, long numrecs )
{
    int recnum;

    struct trans transact;

    printf( "Transaction number: " );
    while ( scanf( "%d", &recnum )) {                /* Note 4 */
        if ( recnum >= numrecs )
            printf( "Enter a number between 0 and %d\n",numrecs-1 );
        else {
                                                     /* Note 5 */
            fseek( fp, ( long ) recnum*sizeof( transact ), 0 );
            if ( read_trans( &transact ,fp ))
                print_trans( &transact );
            else
                printf( "Transaction %d not found.\n", recnum );
        }
		printf( "Next transaction Number: " );
    }
}

/*******************************getnumrecs()********************/

long int getnumrecs( FILE *fp )
{
    long int numbytes;

    fseek( fp, ( long ) 0, 2 );                      /* Note 6 */
    numbytes = ftell( fp );                          /* Note 7 */
    if ( numbytes != -1 )
        return ( numbytes/sizeof( struct trans ));
    else
        return ( -1L );
}