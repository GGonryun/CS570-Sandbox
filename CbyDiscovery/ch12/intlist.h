//               intlist.h
//
// Contains a declaration of the intList class
// for a list of integers.


class intList {
public:
    intList();
    // PRECONDITION: none.
    //
    // POSTCONDITION: an empty intList is constructed.

    ~intList();
    // PRECONDITION:  none
    //
    // POSTCONDITION: the intList object is destroyed.

    bool insert( int elt, int position );
    // PRECONDITION:  elt is to be inserted at position 
    //                in the list. position should be a 
    //                non-negative integer. A position of 0 denotes 
    //                the front of the list.
    //
    // POSTCONDITION: The return value is true if the 
    //                insertion was done at the prescribed 
    //                position; false if elt could not be 
    //                inserted at that position.

    bool remove( int elt );
    // PRECONDITION:  elt is the integer that is to 
    //                be removed from the intList object.
    //
    // POSTCONDITION: elt is not a list member. Return 
    //                value is true if elt was removed 
    //                from the list. Returns false if elt 
    //                was not a member of the list.

    int search( int elt ) const;
    // PRECONDITION:  elt is the integer to search for.
    //
    // POSTCONDITION: return value is the position in the 
    //                list where elt was found or -1 if 
    //                elt was not found.

    bool retrieve( int position, int& elt );
    // PRECONDITION:  the integer at position is to be retrieved.
    //
    // POSTCONDITION: The return value is true and elt 
    //                contains the list item that is at 
    //                position in the list; the return value 
    //                is false and elt is uninitialized if no 
    //                item is at position in the list.

    bool IsFull() const;
    // PRECONDITION:  none.
    //
    // POSTCONDITION: returns true is the List object
    //                is full, false if not.

    bool IsEmpty() const;
    // PRECONDITION:  none.
    //
    // POSTCONDITION: returns true if the List object
    //                is empty; false, if not.

private:
    // Private data members omitted.
};
