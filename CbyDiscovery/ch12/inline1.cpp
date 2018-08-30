//					inline1.cpp
//
// Synopsis  - The program prompts for and accepts input of a
//             decimal integer.  It then tests to see if that
//             integer is even or odd.  The results of the
//             test are displayed.
//
// Objective - Illustrates functions and control statements 
//             in C++ and the use of an inline function that
//             returns type bool.

// Include Files 
#include <iostream.h>

// Function Prototypes
inline bool odd ( int intvar );	                      // Note 1
// PRECONDITION:  none
//
// POSTCONDITION: If intvar is even, the function returns false.
//                If intvar is odd the function returns true.

int main()													
{
    int intvar;
    cout << "Enter a decimal integer: ";
    cin >> intvar;

    if ( odd( intvar ) )                              // Note 2
        cout << intvar << " is odd.\n";
    else
        cout << intvar << " is even.\n";
    return 0;
}

//******************************odd()****************************
inline bool odd( int intvar )                         // Note 3
{
    return( (intvar % 2) == 1 );                      // Note 4
}
