//                          invItem.h
//
// Declaration of the invItem class
class invItem {
public:
    invItem();                                       // Note 2
    // PRECONDITION:  none
    //
    // POSTCONDITION: The data members of the object have
    //                been initialized to default values.

    invItem( const invItem& item );                  // Note 3
    // PRECONDITION:  none
    //
    // POSTCONDITION: the constructed object is a copy of item.

    invItem( char *the_id, int the_num = 0 );        // Note 4
    // PRECONDITION:  none
    //
    // POSTCONDITION: the object is constructed with id equal the_id 
    //                andnum_available equal the_num.

    ~invItem();                                      // Note 5
    // PRECONDITION:  none
    //
    // POSTCONDITION: the object has been properly destroyed.

    bool changeNum( int change_amt );                // Note 6
    // PRECONDITION:  change_amt should be the amount by which the
    //                number in the inventory has changed.
    // POSTCONDITION: If change_amt is positive, num_available 
    //                will be incremented by change_amt and 
    //                true will be returned. If change_amt is 
    //                negative, the return value will be true 
    //                if num_available+change_amt
    //                is greater or equal to 0. The new value 
    //                of num_available will be num_available + 
    //                change_amt. If change_amt is negative and 
    //                num_available+change_amt is also negative,
    //                the return value will be false and
    //                change_amt will remain unchanged.

    bool changeId( char *newId );                    // Note 7
    // PRECONDITION:  newId should be a null terminated 
    //                C style string.
    // POSTCONDITION: The id has been changed to newId; the return
    //                value is true.

    const char * getId() const { return id; }        // Note 8
    // PRECONDITION:  none
    //
    // POSTCONDITION: the return value is the item's id.

    int whatsLeft() const { return num_available; }	
    // PRECONDITION:  none
    //
    // POSTCONDITION: the return value is num_available

    void display();
    // PRECONDITION:  none
    //
    // POSTCONDITION: the id and number in inventory
    //                have been displayed on standard output

private:
    char *id;                                        // Note 1
    int num_available;
};