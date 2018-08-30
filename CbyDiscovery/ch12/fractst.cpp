//             fractst.cpp
//
// Synopsis  - Instantiates and displays three Fraction objects. 
//             Then the results of the Fraction unary - and 
//             Fraction addition are calculated and displayed.
//
// Objective - To demonstrate the Fraction class and
//             the overloading of operators for a 
//             Fraction object.

// Include Files
#include <iostream.h>
#include "fraction.h"

int main()
{
    Fraction f1(4, 5), f2(4, -3), f3;

    cout << f1 << endl;                              // Note 1
    cout << f2 << endl;
    cout << f3 << endl;

    f3 = -f1;                                        // Note 2
    cout << f3 << endl;

    f3 = f1 + f2;                                    // Note 3
    cout << f3 << endl;
    return 0;
}