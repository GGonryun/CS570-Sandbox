//             tstemply.cpp
//
// Synopsis  - Instantiates an employee and a manager.
//             Prints information about both. Makes the 
//             employee part of the manager's group and
//             gives them both raises.
//
// Objective - To study public inheritance and see the 
//             expanded capabilities of the manager
//             class and code reuse.
//

// Include Files
#include <iostream.h>
#include "employee.h"

int main()
{
    employee e1( "Sam", 50000, 8 );
    manager m1( "Joan", 72000, 10, 104 );            // Note 1

    e1.print();                                      // Note 2
    m1.print();                                      // Note 5
    cout << endl << endl;

    m1.set_group( e1 );                              // Note 4
    m1.print();                                      // Note 5
    cout << endl << endl;

    e1.salary_set( 58000 );
    m1.salary_set( 80000 );                          // Note 3
    m1.print();                                      // Note 5

    return 0;
}
