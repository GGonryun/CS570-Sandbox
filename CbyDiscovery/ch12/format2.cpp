//             format2.cpp

#include <iostream.h>

int main()
{
    cout.width( 4 );
    cout << 8 << endl;

    cout.fill( '0' );
    cout.width( 8 );
    cout << 321 << endl;
    cout.setf( ios::left );
    cout.width( 8 );
    cout << 321 << endl;

    cout.precision(2);
    cout.width(8);
    cout << 321.123 << endl;
    cout.setf( ios::fixed );
    cout << 321.123 << endl;

    cout.unsetf( ios::fixed );
    cout.setf( ios::scientific );
    cout << 321.123 << endl;
    cout << cout.width() << endl;

    return 0;
}