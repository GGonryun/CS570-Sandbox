//             vectralg.cpp
//
// Synopsis  - Instantiates STL vector objects, and STL
//             iterators. Applies some STL algorithms to
//             the vector containers.
//
// Objective - To introduce the concepts of STL in general
//             and the vector container in STL in particular.
//

// Include files
#include <vector>                                    // Note 1
#include <algorithm>
#include <iostream.h>

using namespace std;                                 // Note 2

void display( vector<int> v ); 
// PRECONDITION:  none. 
//
// POSTCONDITION: The elements and some properties of v 
//                have been displayed on cout.

void reverseIt( vector<int> v );
// PRECONDITION:  none.
//
// POSTCONDITION: The elements in v have been displayed 
//                on cout in reverse order.

void copyex( vector<int> v, vector<int> v1 );
// PRECONDITION:  none. 
//
// POSTCONDITION: No change has occured to the parameters. The 
//                results of invocations of the algorithm copy() 
//                are displayed on standard output.

void for_each_ex( vector<int>& v ); 
// PRECONDITION:  none.
//
// POSTCONDITION: Every integer in the vector will 
//                have been multiplied by 2.

void mult_by_2( int& x );
// PRECONDITION:  none.
//
// POSTCONDITION: x will be changed by multiplying it by 2.

int main ()
{
    vector<int> v1;                                  // Note 3

    v1.push_back (21);                               // Note 4
    v1.push_back (4);
    v1.push_back (16);

    cout << "Displaying vector v1:\n";
    display( v1 );

    cout << "Displaying the elements of v in reverse\n" ;
    reverseIt( v1 );

    vector<int> v2;
    cout << "Displaying vector v2:\n";
    display( v2 );

    v2.resize( 3 );                                  // Note 5
    cout << "Displaying vector v2 after resizing:\n";
    display( v2 );

    cout << "Copy Example\n";
    copyex( v1, v2 );

    cout << "for_each example\n";
    for_each_ex( v1 );

    while ( !v1.empty() ) {                          // Note 6
        v1.pop_back();                               // Note 7
    }
    cout << "Displaying vector v1 after pop_back operations:\n";
    display( v1 );

    return 0;
}

/******************************** display() ******************/
void display( vector<int> v )
{
    vector<int>::iterator it;                        // Note 8
    if (v.empty() )                                  // Note 6
        cout << "Vector is empty\n\n";
    else {
        cout << "size () = " << v.size () << endl;   // Note 9
        cout << "front() is " << v.front() << endl;  // Note 10
        cout << "back() is " << v.back() << endl;    // Note 11
        for ( it = v.begin(); it != v.end(); it++ )  // Note 12	
            cout << *it << " ";                      // Note 13
        cout << endl << endl;
    }
}

/******************************** display() ******************/
void reverseIt( vector<int> v )
{
	vector<int>::reverse_iterator p2;                // Note 14
	for( p2 = v.rbegin(); p2 != v.rend(); p2++ )     // Note 15
		cout << *p2 << " ";
	cout << endl << endl;
}

/******************************** copyex() *******************/
void copyex( vector<int> v, vector<int> v1 )
{
    vector<int>::reverse_iterator r_it = v1.rbegin();	
    copy( v.begin(), v.end(), r_it );                // Note 16
    cout << "Displaying the second parameter to "
         << "copyex after the first copy:\n";
    display( v1 );

    if ( v == v1 )
        cout << "v equals v1\n\n";
    else cout << "v does not equal v1\n\n";

    copy( v.begin(), v.end(), v1.begin() );          // Note 16
    cout << "Displaying the second parameter to "
         << "copyex after the second copy:\n";
    display( v1 );
	
    if ( v == v1 )                                   // Note 17
        cout << "v equals v1\n\n";
    else cout << "v does not equal v1\n\n";

    return;
}

/******************************** for_each_ex() **************/
void for_each_ex( vector<int>& v )
{
    for_each( v.begin(), v.end(), mult_by_2 );       // Note 18
    cout << "Displaying vector v after the for_each:\n";
	display( v );
} 

/******************************** mult_by_2() ****************/
void mult_by_2( int& x  )
{
    x *= 2;
}
