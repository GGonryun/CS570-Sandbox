//             format.cpp
//
// Synopsis  - Displays the integer 12 in different 
//             formats. Then displays the floating 
//             point number 12.3456789 in different formats.
//
// Objective - To explore the formatting facilities in C++.
//

//Include Files
#include <iostream.h>

int main()
{
                                                     // Note 1
    cout << 12 << endl;
    cout << "Default width is " << cout.width() << endl;
    cout.width( 8 );
    cout << 12 << endl;
    cout << 12 << endl << endl;

                                                     // Note 2
    cout << "Default fill character = '"
	     << cout.fill() << "'" << endl;
    cout.fill( '.' );
    cout << "Now fill character is '" 
		 << cout.fill() << "'" << endl;
    cout.width( 8 );
    cout << 12 << endl << endl;

                                                     // Note 3
    cout.setf( ios::hex | ios::uppercase );
    cout << "Integer output set to hex and uppercase\n";
    cout.width( 8 );
    cout << 12 << endl << endl;

                                                     // Note 4
    int precisn = cout.precision();
    cout << "Default precision is " << precisn << endl;
    cout << 12.3456789 << endl;
    cout.precision(2);
    cout << "Now precision is " << cout.precision() << endl;
    cout << 12.3456789 << endl << endl;

                                                     // Note 5
    cout.setf( ios::fixed );
    cout << "Floating point output has been set to fixed "
         << "and precision is " << cout.precision() << ".\n";
    cout << 12.3456789 << endl;
    cout.precision( 6 );
    cout << "Now with precision " << cout.precision() 
         << " and fixed floating point output.\n";
    cout << 12.3456789 << endl << endl;
    cout.unsetf( ios::fixed );
    cout.setf( ios::scientific );
    cout << "With scientific floating point output "
         << "and precision " << cout.precision() << endl;
    cout << 12.3456789 << endl;

    return 0;
}
