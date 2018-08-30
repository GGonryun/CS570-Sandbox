/*     la9.c
*/
	
/* Include Files */
#include <stdio.h>
	
/* Global Variables */
    int a, b, c;
	
/* Function Declarations */
    void f1( void );
    void f2( void );

int main( void )
{
    int a;
    a = 5;
    b = 3;
    c = 7;
    printf( "%d, %d, %d\n", a, b, c );
    f1();
    printf( "%d, %d, %d\n", a, b, c );
    return 0;
}
	
int d = 4;
	
void f1( void )
{
    char c = 'A';
	
    a = 3;
    b++;
    printf( "%d, %d, %d, %d\n", a, b, c, d );
    f2();
    printf( "%d, %d, %d, %d\n", a, b, c, d );
}
	
void f2( void )
{
    int d = 45;

    a += 4;
    b = 7;
    c = d + a;
    printf( "%d, %d, %d, %d\n", a, b, c, d );
}