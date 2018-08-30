//              fraction.h
//
// Contains the declaration of the Fraction class

// Include Files
#include <iostream.h>								

class Fraction {
                                                     // Note 1
    friend ostream& operator << ( ostream& str, Fraction f );
    // PRECONDITION:  str must be available for output.
    //
    // POSTCONDITION: f will be written to str.

public:
    Fraction() {  num = 0; denom = 1; }
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the object is initialized as 0/1.

    Fraction ( int n, int d );
    // PRECONDITION:  none.
    //
    // POSTCONDITION: If d is not equal to 0, the object is 
    //                initialized as n/d. Otherwise it is 
    //                initialized as 0/1.

    int numerator() const { return num; }
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the value of num is returned.

    int denominator() const { return denom; }
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the value of denom is returned.

    Fraction operator -() const;                     // Note 2
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the return value is the negative 
    //                of the invoking object.

    Fraction operator +( Fraction f ) const;         // Note 3
    // PRECONDITION:  none.
    //
    // POSTCONDITION: The return value is the fraction sum of
    //                the invoking object and f.

private:
    int num;
    int denom;
};
