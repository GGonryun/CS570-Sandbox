//             invMain.cpp
//
// Synopsis  - Creates invItem objects with different constructors.
//
// Objective - To illustrate constructors and destructors.

// Include Files
#include <iostream.h>
#include "invItem.h"

int main()
{
    invItem default_item;                            // Note 1
    cout << "Initial values for default_item: ";
    default_item.display();
    default_item.changeId( "AB1111F" );
    default_item.changeNum( 50 );
    cout << "Modified values for default_item: ";
    default_item.display();
    invItem copied_item( default_item );             // Note 2
    cout << "Initial values for copied_item: ";
    copied_item.display();
	
    invItem another_item( "A1234H" );                // Note 3
    cout << "Initial values for another_item: ";
    another_item.display();
    invItem another_copy = another_item;             // Note 4
    cout << "Initial values for another_copy: ";
    another_copy.display();
	
    return 0;
}
