//             ovrload1.cpp
//
// Synopsis  - Displays the sum of two double variables 
//             and the sum of the first four elements
//             of an array.
//
// Objective - To demonstrate overloaded functions.
//

// Include Files
#include <iostream.h>
// Function Prototypes
double sum( double a, double b );                    // Note 1
// PRECONDITION:  none.
//
// POSTCONDITION: the return value is the sum of a and b.

int sum( int array[], int n );                       // Note 2
// PRECONDITION:  array must have n or more cells
//
// POSTCONDITION: the return value is the sum of the
//                first n cells in array.

int main()
{
    int an_array[] = { 3, 5, 7, 12, 2, 15, 4, 8 };
    double x = 53.12, y = 45.872;

    cout << "The sum of x and y is " 
         << sum( x, y ) << endl;                     // Note 3

    cout << "The sum of the first four elements of an_array is "
         << sum( an_array, 4 ) << endl;              // Note 4

    return 0;
}

/*************************** sum( double, double ) **********/
double sum( double a, double b )                     // Note 1
{
    return ( a + b );
}

/*************************** sum( int[], int ) **************/
int sum( int array[], int n )                        // Note 2
{
    int the_sum = 0;

    for ( int i = 0; i < n; i ++ )
        the_sum += array[i];

    return the_sum;
}