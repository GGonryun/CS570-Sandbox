/*             epp8.c
*/

/* Include Files */
#include <stdio.h> 
#include "mystring.h" 
	               
int main( void )
{
struct string str1,
    str2 = { "how now brown cow", 17 };

    str1.length = 0;
    printf( "Length of str1 - %d\n", mystrlen( str1 ));

    mystrcat( str1, str2 );
    print_string( str1 );
    printf( "\nLength of str1 - %d\n", mystrlen( str1 ));
    return 0;
}