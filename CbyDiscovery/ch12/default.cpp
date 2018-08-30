//             default.cpp
//
// Synopsis  - Prompts for and accepts input of the price of an 
//             item and displays the price of a case of items.
//
// Objective - To illustrate default values for function 
//             parameters.

// Include Files
#include <iostream.h>

// Function Prototypes
double case_price( double item_cost, int case_size = 12 );  // Note 1
// PRECONDITION:  item_cost is the cost of a single item. 
//                case_size is the number of items in a case.
//
// POSTCONDITION: The function returns the price of a case of 
//                case_size items that cost item_cost each

int main()
{
    cout << "The price of a case of items.\n"
	     << " ----------------------------\n\n";
    cout << "Enter the price of a single item now: $ ";
    double price;                                           // Note 2
    cin >> price;

    cout << "If the case consists of 12 items, "
         << "the case price will be $ "
         << case_price( price ) << endl << endl;            // Note 3

    cout << "If the case consists of 24 items, "
         << "the case price will be $ "
         << case_price( price, 24 ) << endl;	            // Note 4
    return 0;
}

/**************************** case_price ***************************/

double case_price( double item_cost, int case_size )        // Note 5
{
    return (item_cost * case_size);
}
