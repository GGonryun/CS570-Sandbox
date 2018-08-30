//             area.cpp
//
// Synopsis  - Prompts for and accepts input of the height and 
//             width of a rectangle, and displays the area of the 
//             rectangle.
//
// Objective - To study the input stream cin, the extraction 
//             operator, >>, and discover more about output in 
//             C++.

// Include Files
#include <iostream.h>

int main()
{
    int width, height;                                   // Note 1
    cout << "Area of a Rectangle\n"                      // Note 2
         << "-------------------\n\n";

    cout << "Enter the height: ";
    cin  >> height;                                      // Note 3

    cout << "Enter the width: ";
    cin  >> width;                                       // Note 3
                                                         // Note 4
    cout << "The area is " << height * width << "\n";
    return 0;
}
