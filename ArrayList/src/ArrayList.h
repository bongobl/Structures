/*************************************************************************
ArrayList.h
This file allows for the creation of ArrayList objects to store longs. 
It dynamically allocates and deallocates memory as the size of the array 
grows and shrinks.
*************************************************************************/
#ifndef ARRAY_LIST
#define ARRAY_LIST

/* struct ArrayList
defines an object of type ArrayList.
Every ArrayList has a long array, an occupancy and the current size of the array
*/
typedef struct{
	int occupancy;
	int arraySize;
	long* the_array;
}ArrayList;

/* new_ArrayList
creates a new empty ArrayList object and allocates all associated memory
and returns a pointer to it.
*/
ArrayList* new_ArrayList();

/* delete_List
dealloocates the list pointed to by list_pp
*/
void delete_List(ArrayList** list_pp);

/* is_empty_List
takes in a pointer to a list, returns 1 if the list is emptu and 0 if not.
*/
int is_empty_List(ArrayList* list);

/* clear_List
empties all items in the list pointed to by list
*/
void clear_List(ArrayList* list);

/* insert_List
inserts item into list at spot index
*/
void insert_List(ArrayList* list,int index,long item);

/* remove_List
removes the item from list at spot index
*/
long remove_List(ArrayList* list, int index);

/* write_List
displays all the items in a list and their indexes
*/
void write_List(ArrayList* list);

/* get_at_index
returns the item in list at spot index
*/
long get_at_index(ArrayList* list,int index);

/* set_at_index
sets the item at index of list to item
*/
void set_at_index(ArrayList* list, int index,long item);


#endif