//                      array.h
//
// Contains the declaration and implementation
// of a template array class.

// Include Files
#include <stdlib.h>

template< class T, int n >                                // Note 1
class Array
{
public:
    Array();
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the array has been initialized 
    //                with all bits set to 0.

    Array( const Array<T,n>& A );                         // Note 2
    // PRECONDITION:  none.
    //
    // POSTCONDITION: the newly created array is a copy of A.

    bool operator == ( Array<T,n>& A ) const;             // Note 2
    // PRECONDITION:  none.
    //
    // POSTCONDITION: Returns true if the two arrays 
    //                have identical elements and false, if not.

    T& operator[]( int index );
    // PRECONDITION:  index mst be greater than or equal 
    //                to 0 and less than n.
    // POSTCONDITION: The element at position index in 
    //                the array is returned.

private:
    T elts[ n ];
};

template< class T, int n >                                // Note 1
Array<T,n>::Array()                                       // Note 3
{
    for ( int i = 0; i < n; i++ )
        elts[i] = T();
}

template< class T, int n >                                // Note 1
Array<T,n>::Array( const Array<T,n>& A )             // Notes 2 & 3
{
    for ( int i = 0; i < n; i++ )
        elts[i] = A.elts[i];
}
template< class T, int n >                                // Note 1
bool Array<T,n>::operator== ( Array<T,n>& A ) const  // Notes 2 & 3
{
    bool match = true;

    for ( int i = 0; i < n; i++ )
        if ( elts[i] != A.elts[i] )
            match = false;
    return match;
}

template< class T, int n >                                // Note 1
T& Array<T,n>::operator[]( int index )                    // Note 3
{
    if ( index < 0 || index >= n ) {
        cerr << "Index out of range\n";	                  // Note 4
        exit( 1 );
    }
    return elts[ index ];
}

