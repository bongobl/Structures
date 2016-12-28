/*************************************************************************
LinkedList.h
This file allows for the creation of LinkedList objects to store longs. 
It dynamically allocates and deallocates memory as the size of the list
grows and shrinks. This list is doubly linked and circular, meaning
the next field of the last node points to the first node and the pre field
of the first node points to the last node.
*************************************************************************/
#ifndef LINKED_LIST
#define LINKED_LIST

/* struct Node
container object to store an element, contains fields to store
the address of the next and the previous node in the list.
*/
typedef struct Node{
	struct Node* next;
	struct Node* pre;
	long element;

}Node;

/* struct LinnkedList
defines an object of type LinkedList.
Every LinkedList has an occupancy and the address of the first node.
*/
typedef struct{
	int occupancy;
	Node* end;

}LinkedList;

/* new_LinkedList
creates a new empty LinkedList object and allocates all associated memory
and returns a pointer to it.
*/
LinkedList* new_LinkedList();

/* delete_List
dealloocates the list pointed to by list_pp
*/
void delete_List(LinkedList** list_pp);

/* is_empty_List
takes in a pointer to a list, returns 1 if the list is emptu and 0 if not.
*/
int is_empty_List(LinkedList* list);

/* clear_List
empties all items in the list pointed to by list
*/
void clear_List(LinkedList* list);

/* advance_next_List
sets the end pointer to the next element in the list
effectively making the first element the last element
*/
void advance_next_List(LinkedList* list);

/* advance_pre_List
sets the end pointer to the previous element in the list
effectively making the last element the first element
*/
void advance_pre_List(LinkedList* list);

/* insert_List
inserts item into list at spot index
*/
void insert_List(LinkedList* list,int index,long item);

/* remove_List
removes the item from list at spot index
*/
long remove_List(LinkedList* list, int index);

/* get_at_index
returns the item in list at spot index
*/
long get_at_index(LinkedList* list,int index);

/* set_at_index
sets the item at index of list to item
*/
void set_at_index(LinkedList* list, int index,long item);

/* write_List
displays all the items in a list and their indexes
*/
void write_List(LinkedList* list);

/* write_reverse_List
displays all the items in a list and their indexes
in reverse order
*/
void write_reverse_List(LinkedList* list);

#endif