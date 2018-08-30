//                   fraction.cpp
//
// Contains an implementation of the function
// members of the Fraction class

// Include Files
#include <iostream.h>
#include "fraction.h"

Fraction::Fraction ( int n, int d )
{
    if ( d != 0 ) {
        if ( d > 0 ) {
            num = n;
            denom = d;
        }
        else {
            num = -n;
            denom = -d;
        }	
    }
    else {
        num = 0;
        denom = 1;
    }
}

Fraction Fraction::operator -() const                // Note 1
{
	Fraction tmp( -num, denom );
	if ( tmp.denom < 0 ) {
		tmp.num = -tmp.num;
		tmp.denom = -tmp.denom;
	}
	return tmp;
}
Fraction Fraction::operator +( Fraction f ) const    // Note 2
{
    Fraction tmp;

    tmp.num = num*f.denom + denom*f.num;
    tmp.denom = denom * f.denom;

    if ( tmp.denom < 0 ) {
        tmp.num = -tmp.num;
        tmp.denom = -tmp.denom;
    }
    return tmp;
}

ostream& operator << ( ostream& str, Fraction f )    // Note 3
{
    str << f.num << "/" << f.denom;
    return str;
}
