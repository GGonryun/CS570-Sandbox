//             io1.cpp
//
// Synopsis  - Prompts for and accepts input of a 
//             character, and echoes it to the terminal
//             screen. Prompts for and accepts input 
//             of a line of text and echoes it to 
//             the screen.
//
// Objective - To demonstrate the use of cout and cin 
//             member functions
//

// Include Files
#include <iostream.h>
#include <string.h>

int main()
{
    char ch;
    char array[80];
    cout << "Please enter a character: ";
    cin.get( ch );                                   // Note 1
    cout.put( '|' );                                 // Note 2
    cout.put( ch );
    cout.put( '|' );
    cout.put( '\n' );

    cin.ignore();                                   // Note 3

    cout << "Enter a line of text: ";
    cin.getline( array, 80 );                       // Note 4
    cout.write( array, strlen(array) );             // Note 5
    cout << endl;

    return 0;
}
