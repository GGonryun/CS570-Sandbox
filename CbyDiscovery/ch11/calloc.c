/*             calloc.c
 *
 * Synopsis  - Reads transactions (elements of type struct 
 *             trans) from a file into a dynamically allocated
 *             array and displays them on standard output.
 *
 * Objective - To illustrate the use of calloc() in allocating
 *             space for an array of structures.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>

/* Constant Declarations */                               /* Note 1 */
#define BUFFSIZE  50

/* Type Descriptions */
struct trans {
    int      t_type;
    char     payee_memo[BUFFSIZE];
    float    amount;
    unsigned tax_deduct:1;
    unsigned cleared:1;
};

/* Function Declarations */
void print_trans(struct trans *outtrans);
/* PRECONDITION:  the parameter outtrans contains the address of a 
 *                struct trans declared by the calling function
 *
 * POSTCONDITION: displays the contents of the structure outtrans on 
 *                standard output; each field is separated with a 
 *                vertical bar character
 */

int main( void )
{
    struct trans *t_array;
    FILE *fp;
    int i, nrecs;
    long numbytes;

    if (( fp = fopen( "transact", "r" )) == NULL ) {
        printf( "Transaction file couldn't be opened.\n" );
        exit( 1 );
    }

    fseek( fp, 0L, 2 );                                   /* Note 2 */
    numbytes = ftell( fp );
    nrecs = (int ) numbytes / sizeof( struct trans );

                                                          /* Note 3 */
    if (( t_array = ( struct trans * )calloc( nrecs, sizeof( struct trans ))) == NULL ) {
        printf( "Unable to get the space.\n" );
        exit( 1 );
    }

    fseek( fp, 0L, 0 );                                   /* Note 4 */
                                                          /* Note 5 */
    if ( !( fread( t_array, sizeof( *t_array ), nrecs, fp ))) {
        printf( "Error in reading the file\n" );
        exit( 2 );
    }

    for ( i = 0; i < nrecs; i++ )
        print_trans( &t_array[i] );
    free( ( void * )t_array );
    fclose( fp );
    return 0;
}

/******************************* print_trans() *******************/

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