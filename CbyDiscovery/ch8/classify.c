/*             classify.c
 *
 * Synopsis  - Reads through English sentence input and counts
 *             each sentence that ends with '.', '?', or '!'
 *             as a statement, a question, or an exclamation.
 *
 * Objective - To illustrate checking the return value of a 
 *             function as well as the value of a parameter.
 */

/* Include Files */
#include <stdio.h>

/* Function Prototypes */
extern int endofsen( int *punctptr );

int main( void )
{
    int punct;
    int statementcounter = 0,
        questioncounter  = 0,
        exclaimcounter   = 0;

    printf( "Enter English sentences as input.  " );
    printf( "Terminate input with an End of File mark.\n" );

    while ( endofsen( &punct )) {                      /* Note 1 */
        if ( punct == '.' )                            /* Note 2 */
            statementcounter++;
        else if ( punct == '?' )
            questioncounter++;
        else if ( punct == '!' )
            exclaimcounter++;
    }
    printf( "\n%d statements, %d questions, ", statementcounter, questioncounter );
    printf( "and %d exclamations.\n",  exclaimcounter );
    return 0;
}