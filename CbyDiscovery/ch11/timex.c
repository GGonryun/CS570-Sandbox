/*             timex.c
 *
 * Synopsis  - Displays today's time and date, the date
 *             tomorrow, and the processor time used by
 *             the program.
 *
 * Objective - To introduce the time and date library
 *             functions.
 */

/* Include Files */
#include <time.h>                                          /* Note 1 */
#include <stdio.h>

int main( void )
{
    time_t t1;                                             /* Note 2 */
    struct tm *tptr;
    clock_t ticks;                                         /* Note 2 */
    char *s;

                                                           /* Note 3 */
    if ( ( t1 = time(( time_t * ) 0 )) != ( time_t )-1 ) {
        s = ctime( &t1 );                                  /* Note 4 */
        printf( "currentdate is %s", s );
        tptr = localtime( &t1 );                           /* Note 5 */
        printf( "Tomorrow is %d/%d/19%d.\n",               /* Note 6 */
                                       tptr->tm_mon+1, 
                                       tptr->tm_mday+1,
                                       tptr->tm_year );
    }
    else
        printf( "Error with the time() function\n" );

                                                           /* Note 7 */
    if (( ticks = clock() ) != ( clock_t )-1 )
        printf( "%4.2f seconds used by the processor.\n",
                                  (double)ticks/CLK_TCK ); /* Note 8 */
    else
        printf( "Error with the clock() function\n" );
    return 0;
}