/*             linklist.c
 *
 * Synopsis  - Echoes its input to its output, but keeps the
 *             input in a linked list.
 *
 * Objective - Illustrates building a linked list of words
 *             with dynamic allocation of memory.
 */

/* Include Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Type Descriptions */
struct node {                                            /* Note 1 */
    char *word;
    struct node *next;
};

/* Function Declarations */
char *get_word_space( char *s );
/* PRECONDITION:  s contains the address of a string declared in the 
 *                calling function
 *
 * POSTCONDITION: Allocates space for the string contained in its
 *                first parameter. Returns a pointer to the first 
 *                byte
 */

struct node *get_node_space( void );
/* PRECONDITION:  none
 *
 * POSTCONDITION: Allocates the space for a single node and returns 
 *                the pointer to the first byte of the space
 */

void release( struct node **listptr );
/* PRECONDITION:  listptr is a pointer to the struct node * value 
 *                that represents the list
 *
 * POSTCONDITION: systematically de-allocates the memory used by the 
 *                list; works from the front of the list to the 
 *                back
 */

void print( struct node *ptr );
/* PRECONDITION:  ptr is a pointer to a struct node
 *
 * POSTCONDITION: displays the contents of the word member of nodes 
 *                in the list
 */

void hook_it_up( struct node *old_list, struct node *new_node );
/* PRECONDITION:  old_list and new_node are pointers to struct nodes
 *
 * POSTCONDITION: attaches new_node to the end of a list; the 
 *                parameter old_list must point to the last node in 
 *                the list
 */

int main( void )
{
    char inputbuffer[512];
    struct node  *list, *lead_ptr, *follow_ptr;

    printf ( "Enter some text for the linked list.\n" );
    printf( "Terminate input by signaling end of file.\n" );
    if ( gets( inputbuffer ) != NULL ) {                  /* Note 2 */
	list = get_node_space();                          /* Note 3 */
        list->next = NULL;                                /* Note 4 */
        follow_ptr = list;
                                                          /* Note 5 */
        list->word = get_word_space( inputbuffer );
        strcpy( list->word, inputbuffer );                /* Note 6 */
    }
    while ( gets( inputbuffer ) != NULL ) {
        lead_ptr = get_node_space();                      /* Note 7 */
        hook_it_up( follow_ptr, lead_ptr );               /* Note 8 */
        follow_ptr = lead_ptr;                            /* Note 9 */
                                                         /* Note 10 */
        lead_ptr->word = get_word_space( inputbuffer );
                                                         /* Note 11 */
        strcpy( lead_ptr->word, inputbuffer );
    }

    printf("\nThe list contains:\n");
    print( list );
    release( &list );                                    /* Note 12 */
    return 0;
}

/******************************* get_node_space() ****************/

struct node *get_node_space( void )
{
    struct node *temp_ptr;
                                                         /* Note 1 */
    temp_ptr = ( struct node * ) malloc( sizeof( struct node ));
    if ( temp_ptr == NULL ) {
        printf( "out of memory for nodes\n" );
        exit( 1 );
    }
    return ( temp_ptr );
}

/******************************* hook_it_up() ********************/

void hook_it_up( struct node *old_list, struct node *new_node )
{
    new_node->next = NULL;
    old_list->next = new_node;
}

/******************************* get_word_space() ****************/

char *get_word_space( char *string )
{
    char *temp;

    temp = ( char * ) calloc( strlen( string ) + 1, 1 );
    if ( temp == NULL ) {
        printf( "Out of memory for text.\n" );
        exit( 2 );
    }
    return ( temp );
}

/******************************* release() ***********************/

void release( struct node **listptr )                     /* Note 1 */
{
    struct node *temp1, *temp2;

    temp1 = *listptr;
    while ( temp1->next != NULL ) {
        temp2 = temp1->next;
        free(( void * )temp1->word );                     /* Note 2 */
        free(( void * )temp1 );
        temp1 = temp2;
    }
    free(( void * )temp1->word );
    free(( void * )temp1 );
    *listptr = NULL;
}

/*******************************print()*************************/

void print( struct node *ptr )
{
    while ( ptr->next != NULL ) {
        printf( "%s\n", ptr->word );
        ptr = ptr->next;
    }
    printf( "%s\n", ptr->word );
}
