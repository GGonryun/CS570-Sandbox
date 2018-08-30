//             file1.cpp
//
// Synopsis  - Opens an ifstream object (an input file)
//             and an ofstream object(an output file)
//             and copies the input file to the output file.
//
// Objective - To introduce file handling in C++.
//

//Include Files
#include <iostream.h>
#include <fstream.h>                                 // Note 1
#include <stdlib.h>

int main()
{
    ifstream infile("info");                         // Note 2

    if ( !infile ) {                                 // Note 3
        cerr << "info couldn't be opened\n";
        exit(1);
    }
    ofstream outfile;                                // Note 4
    outfile.open("copy");                            // Note 5
    if ( !outfile ) {                                // Note 6
        cerr << "copy couldn't be opened\n";
        exit(2);
    }

    char c;
    while( infile.get(c) )                           // Note 7
        outfile.put(c);                              // Note 8

    infile.close();                                  // Note 9
    outfile.close();                                 // Note 9
    return 0;
}
