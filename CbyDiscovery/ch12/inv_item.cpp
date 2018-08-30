//                  inv_item.cpp

// Implementation of inv_item class
#include <iostream.h>
#include <string.h>
#include "invItem.h"

invItem::invItem()	                                 // Note 1
{
    id = new char[5];
    strcpy( id, "####" );
    num_available = 0;
}

invItem::invItem( const invItem& item )              // Note 2
{
    id = new char[ strlen( item.id ) + 1 ];
    strcpy( id, item.id );
    num_available = item.num_available;
}

invItem::invItem( char *the_id, int the_num )        // Note 3
{
    id = new char[ strlen( the_id ) + 1 ];
    strcpy( id, the_id );
    num_available = the_num;
}

invItem::~invItem()                                   // Note 4
{
    delete[] id;											
}

bool invItem::changeNum( int change_amt )									
{
    if ( num_available + change_amt >=0 ) {
        num_available += change_amt;
        return true;
    }
    return false;
}

bool invItem::changeId( char *newId )                // Note 5
{
    char *tmp = new char[ strlen( newId ) + 1 ];
    strcpy( tmp, newId );
    delete[] id;
    id = tmp;
    return true;
}

void invItem::display()
{
    cout << "Id: " << id
         << " - Available " << num_available
         << endl;
}
