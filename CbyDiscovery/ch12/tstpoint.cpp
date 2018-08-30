//             tstpoint.cpp
//
// Synopsis  - The program instantiates two Point objects, 
//             initializes the values, displays the objects, and 
//             calculates and displays the distance of each point 
//             from the origin.
//
// Objective - To demonstrate the instantiation of objects and 
//             the invocation of class member functions by an 
//             object,and passing an object as an argument to a 
//             top-level function.

// Include Files
#include <iostream.h>
#include <math.h>
#include "point.h"                                         // Note 1

// Function Prototypes
double distance_from_origin( Point p );                    // Note 3
// PRECONDITION:  p should have both x and y initialized
//
// POSTCONDITION: The return value is the distance of p
//                from the origin.

int main()
{
    Point p1, p2;                                          // Note 2

    p1.set_x( 0 );                                         // Note 4
    p1.set_y( 0 );                                         // Note 4

    cout << "Point 1 is ";
    p1.display();                                          // Note 4

    p2.set_x( 3 );                                         // Note 5
    p2.set_y( 4 );                                         // Note 5
    cout << " and Point 2 is ";
    p2.display();	                                       // Note 5
    cout << endl;

    cout << "The distance of Point 1 from the origin is "
         << distance_from_origin( p1 ) << endl;            // Note 3

    cout << "The distance of Point 2 from the origin is "
         << distance_from_origin( p2 ) << endl;	           // Note 3

    return 0;
}

/********************************** distance_from_origin() *********/
double distance_from_origin( Point p )
{                                               // Note 4 and Note 5
    return sqrt( p.x_is()*p.x_is() + p.y_is()*p.y_is() );
}
