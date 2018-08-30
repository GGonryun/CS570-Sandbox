//               intstack.h
//
// Contains the declaration of a stack 
// privately derived from class intList

// Include Files
#include "intlist.h"

class intStack: private intList                      // Note 1
{
public:
    intStack();
    // PRECONDITION:  none.
    //
    // POSTCONDITION: an empty stack is created.

    ~intStack();
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the stack is destroyed.

    bool IsEmpty() const;                            // Note 2
    // PRECONDITION:  none.
    //
    // POSTCONDITION: returns true if the stack is 
    //                empty and false if not.

    bool IsFull() const;                             // Note 2
    // PRECONDITION:  none.
    //
    // POSTCONDITION: returns true if the stack 
    //                is full and false if not.

    bool Push( int elt );                            // Note 3
    // PRECONDITION:  elt is to be pushed on the stack.
    //
    // POSTCONDITION: returns true if elt was pushed onto the 
    //                top of the stack; returns false if elt 
    //                could not be pushed on the stack.

    bool Pop();                                      // Note 4
    // PRECONDITION:  none.
    // POSTCONDITION: returns true if an element was 
    //                removed from the stack; returns 
    //                false if not.

    bool Top( int &elt );                            // Note 5
    // PRECONDITION:  none.
    //
    // POSTCONDITION: returns false if the stack is empty 
    //                and elt is unchanged; otherwise, 
    //                returns true and elt contains the 
    //                integer that is on top of the stack.

private:
    // Private data members omitted.
};