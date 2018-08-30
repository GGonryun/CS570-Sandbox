/*             mergsort.c
*/

/* Include Files */
#include "mergsort.h"                                  /* Note 1 */

/******************************* merge_sort() ********************/
                                                       /* Note 2 */
void merge_sort( int to_sort[], int first, int last )
{
    if ( first < last ) {                              /* Note 3 */
                                                       /* Note 4 */
        merge_sort( to_sort, first, (first+last)/2 );
                                                       /* Note 5 */
        merge_sort( to_sort, (first+last)/2 + 1, last );
                                                       /* Note 6 */
        merge( to_sort, first, (first+last)/2, (first+last)/2 + 1, last );
    }
}

/******************************* merge() *************************/

void merge( int lists[], int first1, int last1, int first2, int last2 )
{
    int temp[MAX_ARRAY];
    int index, index1, index2;
    int num;

    index = 0;
    index1 = first1;
    index2 = first2;
    num = last1 - first1 + last2 - first2 + 2;

    /* while there are still elements in both lists,
     * put the smallest element in the temporary array.
     */
    while (( index1 <= last1 ) && ( index2 <= last2 )) {

        if ( lists[index1] < lists[index2] )
            temp[index++] = lists[index1++];
        else
            temp[index++] = lists[index2++];
    }

    /* after one list is empty, fill the temporary array
     * with the remaining elements in the other list
     */
    if ( index1 > last1 )                 /* first list is empty */
        move( lists, index2, last2, temp, index );
    else                                 /* second list is empty */
        move( lists, index1, last1, temp, index );

    /* copy the list to original array */
    move( temp, 0, num-1, lists, first1 );
}

/******************************* move() **************************/

void move( int list1[], int first1, int last1, int list2[], int first2 )
{
    while ( first1 <= last1 )
        list2[ first2++ ] = list1[ first1++ ];
}