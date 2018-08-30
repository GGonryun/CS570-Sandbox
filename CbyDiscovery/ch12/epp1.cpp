//             epp1.cpp
//
//  A simple I/O example

//Include Files
#include <iostream.h>

int main()
{
    int intvar;
    char charvar;
    float floatvar;

    cout << "Enter an int, a char, and a float: ";
    cin >> intvar >> charvar >> floatvar;
    cout << "You entered " << intvar << ", |" << charvar << "|, " << floatvar << "\n";
    return 0;
}