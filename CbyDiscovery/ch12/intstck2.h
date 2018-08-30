//               intstck2.h
//
// Contains the declaration of intStack 
// implemented by containment using class intList
//

// Include Files
#include "intlist.h"

class intStack {
public:
    intStack() {}
    // PRECONDITION:  none
    //
    // POSTCONDITION: an empty stack is created.

    ~intStack() {}
    // PRECONDITION:  none
    //
    // POSTCONDITION: the stack is destroyed

    bool IsEmpty() const;
    // PRECONDITION:  none
    //
    // POSTCONDITION: returns true if the stack is 
    //                empty and false if not.

    bool IsFull() const;
    // PRECONDITION:  none
    //
    // POSTCONDITION: returns true if the stack 
    //                is full and false if not.

    bool Push( int elt );
    // PRECONDITION:  elt is to be pushed on the stack.
    //
    // POSTCONDITION: returns true if elt is at the top 
    //                of the stack; returns false if elt 
    //                could not be pushed on the stack.

    bool Pop();
    // PRECONDITION:  none
    //
    // POSTCONDITION: returns true if an element was 
    //                removed from the stack; returns 
    //                false if not.

    bool Top( int &elt );
    // PRECONDITION:  none
    //
    // POSTCONDITION: returns false if the stack is empty 
    //                and elt is unchanged; otherwise, 
    //                returns true and elt contains the 
    //                integer that is on top of the stack.

private:
	intList l;
};

