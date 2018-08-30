/*             qsort.c
 *
 * Synopsis  - Sorts an array of ints and an array of structures.
 *             The structures are sorted by name (a string) and 
 *             by age (an int). The arrays are displayed before 
 *             and after sorting.
 *
 * Objective - To study and use pointers to functions and study
 *             an example using the library function qsort.
 */
#include <stdio.h>
#include <stdlib.h>                                 /* Note 1 */
#include <string.h>
#define NUMELTS 5
struct member {
    char *name;
    int age;
};
	
/* Function Prototypes */                           /* Note 2 */
int compare_ints( const void *a, const void *b);
/* PRECONDITION:  a and b are pointers to the objects being 
 *                compared.
 *
 * POSTCONDITION: as qsort() requires, the value returned is -1 if 
 *                a is less than *b, 0 if *a and *b are equal, and
 *                1 if *a is greater than *b.
 */

int compare_age( const void *x, const void *y);
/* PRECONDITION:  a and b are pointers to the objects being 
 *                compared.
 *
 * POSTCONDITION: as qsort() requires, the value returned is -1 if 
 *                the age in *a is less
 *                than the age in *b, 0 if the ages are equal, and
 *                1 if the age in *a is greater than that in *b.
 */

int compare_name( const void *x, const void *y);
/* PRECONDITION:  a and b are pointers to the objects
 *                being compared.
 *
 * POSTCONDITION: as qsort() requires, the value returned is -1 if 
 *                the name in *a comes before the name in *b 
 *                alphabetically, 0 if the names are identical, and
 *                1 if the name in *a comes after the name in *b.
 */

void print( char * l, struct member x[], int num );
/* PRECONDITION:  l is a null-terminated string that will be output 
 *                before the contents of the array; x is the array 
 *                of struct members, and num is the number of 
 *                elements in x.
 *
 * POSTCONDITION: the string l is displayed followed by
 *                the contents of x.
 */

void print_ints( char * label, int ints[], int num );
/* PRECONDITION:  label is a null-terminated string that will be 
 *                displayed before the contents of the array; x is the
 *                array of struct members, and num is the number  
 *                of elements in x.
 *
 * POSTCONDITION: the string label is displayed followed 
 *                by the contents of x.
 */
int main(void)
{
    char *list[5] = { "cat", "cart", "cabin", "cap", "can" };
    int integers[6] = { 45, 36, 12, 88, 99, 10 };
    static struct member ary[NUMELTS] =	{  {"ralph", 42},
                                           {"helen", 45},
                                           {"todd", 20},
                                           {"louise", 12},
                                           {"sharon", 23},
                                        };
    print_ints( "Integers before sorting", integers, 6 );
                                                     /* Note 3 */
    qsort((void *)integers, 6, sizeof(integers[0]), compare_ints);
    print_ints( "Integers after sorting", integers, 6 );

    print( "Original array", ary, 5 );
                                                     /* Note 4 */
    qsort( (void *)ary, NUMELTS, sizeof(struct member), compare_age );
    print( "After sorting by age", ary, 5 );
                                                     /* Note 5 */
    qsort( (void *)ary, NUMELTS, sizeof(struct member), compare_name );
    print( "After sorting by name", ary, 5 );
    return 0;
}

/*******************************compare_ints()******************/

int compare_ints( const void *a, const void *b)
{
                                                     /* Note 6 */

    if ( *(int * )a < *( int * )b )
        return(-1);
    else if ( *(int *)a > *(int *)b )
        return(1);
    else
        return(0);
}

/*******************************compare_age()*******************/

int compare_age( const void *x, const void *y)
{
                                                     /* Note 7 */
    if ( ((struct member * )x)->age < ( (struct member * )y)->age )
        return(-1);
    else if ( ((struct member *)x)->age > ((struct member *)y)-> age )
        return(1);
    else
        return(0);
}

/*******************************compare_name()******************/

int compare_name( const void *x, const void *y)
{
                                                     /* Note 8 */
    return ( strcmp( ((struct member * )x)->name, ((struct member * )y)->name ));
}

/*******************************print()*************************/

void print( char *label, struct member array[], int num )
{
    int i;

    printf( "%s\n", label );
    for (i = 0; i < num; i++)
        printf("%s,\t %d\n", array[i].name, array[i].age);
    printf("\n");
}

/*******************************print_ints()********************/

void print_ints( char * label, int ints[], int num )
{
    int i;

    printf( "%s\n", label );
    for (i = 0; i < num; i++)
        printf("%d ", ints[i]);
    printf( "\n");
}