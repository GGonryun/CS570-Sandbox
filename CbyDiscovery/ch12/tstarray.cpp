//             tstarray.cpp
//
// Synopsis  - Two arrays of type int are declared, initialized
//             and tested to see if they are equal. The same is
//             done with two arrays of type char.
//
// Objective - To illustrate using class templates.
//

//Include files
#include <iostream.h>
#include "array.h"                                   // Note 1
// Function Prototypes
template< class T, int n >                           // Note 2
void print( Array<T,n> A );

int main()
{
    Array<int, 5> intarray1, intarray2;              // Note 3
    Array<char, 4> chararray1, chararray2;           // Note 4
    int i;

    for ( i = 0; i < 5; i++ ) {
        intarray1[i] = i;                            // Note 5
        intarray2[i] = 5-(i+1);
    }

    print( intarray1 );                              // Note 6
    print( intarray2 );

    if ( intarray1 == intarray2 )                    // Note 7
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    for ( i = 0; i < 4; i++ ) {
        chararray1[i] = 'a' + i;                     // Note 5
        chararray2[i] = 'a' + i;
    }

    print( chararray1 );                             // Note 6
    print( chararray2 );

    if ( chararray1 == chararray2 )                  // Note 7
        cout << "Equal\n";
    else
    cout << "Not Equal\n";

    return 0;
}

/************************************* print() *********************/
template< class T, int n >                           // Note 2
void print( Array<T,n> A )
{
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";                         // Note 8
	cout << endl;
}
