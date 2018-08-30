/*             stack.c
 *
 *  This file contains the stack utility functions push(), pop(),
 *  init_stack(), is_empty(), and is_full().
 */

/* Include Files */
#include "stack.h"                                   /* Note 1 */

/*******************************init_stack()********************/

void init_stack( STACK *s_ptr )                      /* Note 2 */
{
    s_ptr->top = MAX;                                /* Note 3 */
}

/*******************************is_empty()**********************/

int is_empty( STACK s )
{
    if ( s.top >= MAX )                              /* Note 4 */
        return ( 1 );
    else
        return ( 0 );
}

/*******************************is_full()***********************/

int is_full ( STACK s )
{
    if ( s.top <= 0 )                                /* Note 5 */
        return ( 1 );
    else
        return ( 0 );
}

/*******************************push()**************************/

int push( char item, STACK *s_ptr )
{
    if ( is_full( *s_ptr ) )                         /* Note 6 */
        return ( -1 );
    else {
        s_ptr->top--;                                /* Note 7 */
        s_ptr->elts[ s_ptr->top ] = item;
        return ( 0 );
    }
}

/*******************************pop()***************************/

int pop( STACK *s_ptr )
{
    if ( is_empty( *s_ptr ) )                        /* Note 8 */
        return ( -1 );
    else {
                                                     /* Note 9 */
        return ( s_ptr->elts[ s_ptr->top++ ] );
    }
}