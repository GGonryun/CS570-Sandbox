//              point.cpp
//
// Contains the implementation of the member
// functions for class Point

// Include Files
#include <iostream.h>
#include "point.h"                                   // Note 1

void Point::display() const                          // Note 2
{
    cout << "(" << x << "," << y << ")";
}

bool Point::set_x( int x_val )                       // Note 2
{
    if ( x_val >= 0 ) {
        x = x_val;
        return true;
    }
    x = 0;
    return false;
}

bool Point::set_y( int y_val )                       // Note 2
{
    if ( y_val >= 0 ) {
        y = y_val;
        return true;
    }
    y = 0;
    return false;
}