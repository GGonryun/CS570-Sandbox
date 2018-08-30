/*             driver.c
 *
 * Synopsis  - Displays the value of a variable, increments it,
 *             and displays it again.
 *
 * Objective - To demonstrate a very simple modular program 
 *             with a variable declared externally.
 */

/* Global Variables */
int x = 5;                                            /* Note 1 */

/* Function Prototypes*/
extern void output( void );                           /* Note 2 */
/* PRECONDITION:  none.
 *
 * POSTCONDITION: displays the value of the variable x. 
 *
 */

extern void incr( void );
/* PRECONDITION:  none.
 *
 * POSTCONDITION: increments the variable x. 
 *
 */

int main( void )
{
    output();                                         /* Note 3 */
    incr();
    output();
    return 0;
}
