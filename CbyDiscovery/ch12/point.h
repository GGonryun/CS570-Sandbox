//                    point.h
//
// Contains the class declaration of class Point

class Point {                                        // Note 1
public:                                              // Note 3
    bool set_x( int x_val );                         // Note 6
    // PRECONDITION:  x_val should be a non-negative integer
    //
    // POSTCONDITION: if x_val is non-negative, x will be 
    //                set to x_val and true is returned.
    //                If x_val is negative, x will be set
    //                to 0 and false is returned.

    bool set_y( int y_val );                         // Note 6
    // PRECONDITION:  y_val should be a non-negative integer
    //
    // POSTCONDITION: if y_val is non-negative, y will be 
    //                set to y_val and true is returned.
    //                If y_val is negative, y will be set
    //                to 0 and false is returned.

    int x_is() const { return x; }                   // Note 7
    // PRECONDITION:  the point should have its data initialized.
    //
    // POSTCONDITION: the value of x is returned.

    int y_is() const{  return y; }                   // Note 7
    // PRECONDITION:  the point should have its data initialized.
    //
    // POSTCONDITION: the value of y is returned.

    void display() const;                            // Note 8
    // PRECONDITION:  the point should have its data initialized.
    //
    // POSTCONDITION: the point is displayed on standard output.

private:                                             // Note 4
    int x;                                           // Note 5
    int y;                                           // Note 5
};                                                   // Note 2