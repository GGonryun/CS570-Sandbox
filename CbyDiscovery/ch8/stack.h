/*             stack.h
 *
 *  Contains the declaration of the data type STACK and the
 *  declarations of the stack utility functions. This header
 *  file should be included in every C source file that 
 *  references a STACK or any of its utility functions.
 */

/* Constant Declarations */
#define MAX 8                                     /* Note 1 */

/* Type Descriptions */
typedef  struct {
    char  elts[MAX];
    int   top;
} STACK;                                          /* Note 2 */

/* Stack Utility Function Prototypes */
int push( char item, STACK *s_ptr );              /* Note 3 */
/* PRECONDITION:  s_ptr contains the address of a STACK.
 *
 * POSTCONDITION: Puts a new item on the stack and adjusts top. 
 */

int pop( STACK *s_ptr );
/* PRECONDITION:  s_ptr contains the address of a STACK.
 *
 * POSTCONDITION: Removes an item from the top of the stack, adjusts 
 *                top, and returns the removed item, or -1 if the 
 *                stack was empty. 
 */

void init_stack( STACK *s_ptr );
/* PRECONDITION:  s_ptr contains the address of a STACK.
 *
 * POSTCONDITION: Initializes a stack to an empty state by setting 
 *                top beyond the end of the array. 
 */

int  is_empty( STACK s );
/* PRECONDITION:  s is a STACK structure.
 *
 * POSTCONDITION: Returns 1 if the STACK is empty and 0 if not. 
 */

int  is_full( STACK s );
/* PRECONDITION:  s is a STACK structure.
 *
 * POSTCONDITION: Returns 1 if the STACK is full, and 0 if not. 
 */