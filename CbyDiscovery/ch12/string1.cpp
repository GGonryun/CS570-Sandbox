//             string1.cpp
//
// Synopsis  - Instantiates two string objects. The string
//             objects invoke member functions, and the
//             results are displayed.
//
// Objective - To introduce functions that can be used
//             with strings.
//

// Include Files
#include <string>                                    // Note 1
#include <iostream.h>	
using namespace std ;                                // Note 2

int main()
{
    string strng1("abc");                            // Note 3
    string strng2("def");

    cout << "strng1 = " << strng1.c_str() << endl;   // Note 4

    strng1.append(strng2);                           // Note 5
    cout << "After appending strng2, strng1 = " 
         << strng1.c_str() << endl;

    strng1.append(strng2, 1, 2);                     // Note 6
    cout << "After appending the last two characters "
         << "of strng2,\nstrng1 = " << strng1.c_str() 
         << endl << endl;

    cout << "The character in strng1 at position 2 is " 
         << strng1.at( 2 ) << endl << endl;          // Note 7
    cout << "Size of the strings:" << endl;
    cout << "strng1's size is " 
         << strng1.size() << endl;                   // Note 8
    cout << "strng2's size is " 
         << strng2.length() << endl << endl;         // Note 8

    strng2.assign( strng1, 2, 4 );                   // Note 9
    cout << "After assigning four characters from strng1\n"
         << "(starting at position 2) to strng2, strng2 = " 
         << strng2.c_str() << endl << endl;
    
    cout << "Comparing strng1 to strng2: "
         << strng1.compare( strng2 ) << endl;        // Note 10

    return 0;
}
