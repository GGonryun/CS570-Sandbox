/*             counter.c
 *
 * Synopsis  - Reads standard input and keeps a count of the
 *             number of extra blanks in the input.
 *
 * Objective - To illustrate a loop to read through many
 *             lines of input and a method of having a
 *             function change a pointer parameter.
 */

/* Include Files */
#include <stdio.h>

/* Function Prototypes */
int countem( char ** ptr );                             /* Note 1 */
/* PRECONDITION:  ptr contains the address of a pointer to a blank 
 *                character.
 *
 * POSTCONDITION: Returns the number of blanks it finds and advances 
 *                the pointer to the first nonblank character.
 */

void process_line( char *ptr, int *num_white_ptr );
/* PRECONDITION:  ptr contains the address of a null terminated 
 *                string. num_white_ptr contains the address of
 *                an integer variable in the calling function
 *                that holds the number of excess blanks.
 *
 * POSTCONDITION: Processes a line of text by looking for blanks. On 
 *                return, the number of extra blanks spaces found 
 *                has been added to the value pointed to by 
 *                num_white_ptr. 
 */

int main( void )
{
    char inarray[512], *inptr;                        /* Note 2 */
    int  white_count = 0;

    printf( "Enter text. Signal end of file when done.\n" );
    printf( "> " );

                                                      /* Note 3 */
    while ( ( inptr = gets( inarray ) ) != NULL ) {
                                                      /* Note 4 */
        process_line( inptr , &white_count );
        printf( "> " );
    }
    printf( "\nThere were %d unnecessary spaces.\n", white_count );
    return 0;
}

/*******************************process_line()******************/

void process_line( char *ptr, int *num_white_ptr )
{
    int count;

    while ( *ptr != '\0' ) {
        if ( *ptr == ' ' ) {
            count = countem( &ptr );                 /* Note 5 */
            if ( count >= 2 )
                                                     /* Note 6 */
                *num_white_ptr += count - 1;
        }
        else
            ptr++;
    }
}

/*******************************countem()***********************/

int countem( char **ptr )                            /* Note 7 */
{
    int counter = 0;

    while ( **ptr == ' ' ) {                         /* Note 8 */
        counter++;
        ( *ptr )++;                                  /* Note 9 */
    }
    return( counter );
}