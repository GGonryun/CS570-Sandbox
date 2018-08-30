//                   employee.cpp
//
// Contains the implementation of functions in
// the base class employee and the derived class manager.
//

// Include Files
#include <iostream.h>
#include <string.h>
#include "employee.h"

// The employee class functions
employee::employee()
{
    name = new char[1];
    name[0] = '0';
    salary = 0;
    groupno = 0;
}

employee::employee( const employee& e )
{
    name = NULL;
    *this = e;                                           // Note 1
}

employee::employee( char * n, int s, int g )
{
    name = new char[ strlen( n ) + 1 ];
    strcpy( name, n );
    if ( s >= 0 )
        salary = s;
    else salary = 0;

    if ( g > 0 )
        groupno = g;
    else groupno = 0;
}

employee::~employee()
{
    delete [] name;
}

bool employee::salary_set( int s )
{
    if ( s >= 0 ) {
        salary = s;
        return true;
    }
    return false;
}

void employee::print() const
{
    cout << "Name: " << name
         << "\tSalary: " << salary
         << "\tDepartment: " << groupno << endl;
}

void employee::change_group( int g ) 
{
    if ( g >= 0 )
        groupno = g;
}

employee& employee::operator= ( const employee& emp )
{
    char * tmpname = new char[ strlen( emp.name ) + 1 ];
    strcpy( tmpname, emp.name );
    delete[] name;
    name = tmpname;
    salary = emp.salary;
    groupno = emp.groupno;
    return *this;
}

// The manager class functions

manager::manager( char * n, int s, int g, int o ): 
	employee( n, s, g ), office( o ), num_in_group( 0 )  // Note 2
{}                                                       // Note 3

bool manager::set_group( employee& e )
{
    if ( num_in_group >= 10 )
        return false;
    group[num_in_group] = &e;
    e.change_group( this->get_group() );                 // Note 4
    num_in_group++;
    return true;
}

void manager::print() const
{
    cout << "MANAGER: "; 

    employee::print();                                   // Note 5
    cout << "Office: " << office
         << "\tNumber in the group: " << num_in_group << endl;
    if ( num_in_group > 0 ) {
        cout << "Group Members:\n-----------------------------\n";
        for ( int i = 0; i < num_in_group; i++ )
            group[i]->print();
    }
}
