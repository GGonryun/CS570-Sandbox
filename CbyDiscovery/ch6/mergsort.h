/*             mergsort.h 
 * 
 * Contains declarations necessary for use 
 * of the merge_sort() package. 
 */ 

/* Constant Declarations */
#define MAX_ARRAY 512

/* Function Prototypes */ 
void merge_sort( int to_sort[], int first, int last ); 
/* PRECONDITION:  to_sort is the array with the 
 *                elements to be sorted. first is the 
 *                index of the first element to 
 *                be sorted and last is the index of 
 *                the last element to be sorted.
 *
 * POSTCONDITION: to_sort will contain the elements 
 *                in increasing order.
 */
void merge( int[], int, int, int, int );
/* PRECONDITION:  Two sorted lists reside in the 
 *                array lists. The first list starts 
 *                at index first1 and goes through 
 *                index last1. The second list starts 
 *                at index first2 and goes through 
 *                index last2.
 *
 * POSTCONDITION: A utility function for merge sort, 
 *                merges two sorted lists. The merged 
 *                lists are in the array lists.
 *
 */
void move( int[], int, int, int[], int );
/* PRECONDITION:  list2 must contain enough cells 
 *                after index fiest2 to hold the 
 *                elements in list1 between indices 
 *                first1 and last1.
 *
 * POSTCONDITION: A utility function for merge sort, 
 *                copies the elements in the array 
 *                list1 with indices first1 to last1 
 *                to the array list2 starting at the 
 *                position with index first2.
 */