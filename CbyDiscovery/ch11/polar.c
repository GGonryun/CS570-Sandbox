/*             polar.c
 *
 * Synopsis  - Converts sets of points in Cartesian coordinates
 *             to polar coordinates.
 *
 * Objective - Illustrates the use of some of the mathematics
 *             in the ANSI C library.
 */

/* Include Files */
#include <stdio.h>
#include <math.h>                                        /* Note 1 */
#include <stdlib.h>

/* Constant Declarations */
#define PI 3.14159

/* Type Descriptions */
struct cartesian {
    double x;
    double y;
};

struct polar {
    double radius;
    double angle;
};

/* Function Declarations */
struct polar *to_polar( struct cartesian *cart );
/* PRECONDITION:  cart contains the address of a struct cartesian
 *
 * POSTCONDITION: converts a point from Cartesian coordinates to 
 *                polar coordinates; returns a struct polar
 */

double get_c_coord( char *s );
/* PRECONDITION:  s contains the address of a string
 *
 * POSTCONDITION: reads a string representing a floating point 
 *                number from the keyboard; returns the number as a 
 *                double
 */

int main( void )
{
    struct cartesian cpoint;
    struct polar     *ppoint;
    char             buff[80];
    int              more = 1;

    printf( "Conversion: Cartesian to polar coordinates.\n" );
    while ( more ) {
        cpoint.x = get_c_coord( "x" );
        cpoint.y = get_c_coord( "y" );
        ppoint = to_polar( &cpoint );
        printf( "Polar coordinates: " );
        printf( "radius %5.2lf, angle %5.2lf\n", ppoint->radius, ppoint->angle );
        printf( "Another one? (y/n) " );
        gets( buff );
        if ( buff[0] != 'y' )
            more = 0;
    }
    return 0;
}

/*******************************get_c_coord()*******************/

double get_c_coord( char *s )
{
    char buffer[80];

    printf( "Enter the %s value: ", s );
    gets( buffer );
    return( strtod( buffer, ( char ** )NULL ) );                  /* Note 2 */
}

/*******************************to_polar()**********************/

struct polar *to_polar( struct cartesian *cart )
{
    static struct polar p;
    double temp;

    temp = pow( cart->x, 2 ) + pow( cart->y,2 );                  /* Note 3 */
    p.radius = sqrt( temp );                                      /* Note 4 */
    p.angle = atan2( cart->y, cart->x );                          /* Note 5 */
    if ( p.angle < 0 )
        p.angle += 2 * PI;
    return ( &p );
}
