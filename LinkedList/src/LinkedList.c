#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"




void insert_Node(Node* this_Node,long item);
long remove_Node(Node* this_Node);
long view_Node(Node* this_Node);


void find_location(LinkedList* list, int index){

	int count;
	for(count = 0; count < index; ++count){
		list->end = list->end->next;
	}
}

LinkedList* new_LinkedList(){
	LinkedList* working = (LinkedList*)malloc(sizeof(LinkedList));
	working->occupancy=0;
	working->end = NULL;
	return working;
}
void delete_List(LinkedList** list_pp){
	
	LinkedList* list_in_caller = *list_pp;
	if(list_in_caller == NULL){
		fprintf(stderr," ***Error in delete_List: list does not exist\n\n");
		return;
	}
	clear_List(list_in_caller);
	free(list_in_caller);
	*list_pp = NULL;
}
int is_empty_List(LinkedList* list){
	if(list == NULL){
		fprintf(stderr," ***Error in is_empty_List: list does not exist\n\n");
		return 1;
	}
	if(list->occupancy == 0){
		return 1;
	}
	return 0;
}
void clear_List(LinkedList* list){
	int iter;
	
	if(list == NULL){
		fprintf(stderr," ***Error in clear_List: list does not exist\n\n");
		return;
	}
	
	for(iter = 0;iter < list->occupancy - 1; ++iter){
		advance_next_List(list);
		free(list->end->pre);
	}
	free(list->end);
	list->end = NULL;
	list->occupancy=0;
	
	
}
void advance_next_List(LinkedList* list){
	if(list == NULL){
		fprintf(stderr," ***Error in advance_next_List: list does not exist\n\n");
		return;
	}
	if(list->occupancy == 0){
		return;
	}
	list->end = list->end->next;
}
void advance_pre_List(LinkedList* list){
	if(list == NULL){
		fprintf(stderr," ***Error in advance_pre_List: list does not exist\n\n");
		return;
	}
	if(list->occupancy == 0){
		return;
	}
	list->end = list->end->pre;
}
void insert_List(LinkedList* list,int index,long item){


	Node* working;
	Node* old_end;

	if(list == NULL){
		fprintf(stderr," ***Error in insert_List: list does not exist\n\n");
		return;
	}
	if(index > list->occupancy || index < 0){
		fprintf(stderr," ***Error in insert_List: Index out of range\n");
		return;
	}
	if(list->occupancy == 0){
		working = (Node*)malloc(sizeof(Node));
		working->next = working;
		working->pre = working;
		working->element = item;
		list->end = working;
		++list->occupancy;
		return;
	}
	old_end = list->end;

	find_location(list,index);
	insert_Node(list->end,item);
	if(index == 0)
		list->end = list->end->pre;
	else{
		list->end = old_end;
	}
	++list->occupancy;

	

}
long remove_List(LinkedList* list, int index){
	long item_to_return;
	Node* old_end;

	if(list == NULL){
		fprintf(stderr," ***Error in remove_List: list does not exist\n\n");
		return 0;
	}
	if(index >= list->occupancy || index < 0){
		fprintf(stderr," ***Error in remove_List: Index out of range\n");
		return 0;
	}
	if(list->occupancy == 1){
		item_to_return = list->end->element;
		free(list->end);
		list->end = NULL;
		--list->occupancy;
		return item_to_return;
	}
	if(index == 0)
		old_end = list->end->next;
	else
		old_end = list->end;
	find_location(list,index);
	item_to_return = remove_Node(list->end);

	list->end = old_end;
	--list->occupancy;
	return item_to_return;
	
}
long get_at_index(LinkedList* list,int index){

	Node* old_end = list->end;
	long item_to_return;
	if(list == NULL){
		fprintf(stderr," ***Error in get_at_index: list does not exist\n\n");
		return 0;
	}
	if(index >= list->occupancy || index < 0){
		fprintf(stderr," ***Error in get_at_index: Index out of range\n");
		return 0;
	}
	find_location(list,index);
	item_to_return = view_Node(list->end);
	list->end = old_end;

	return item_to_return;


}
void set_at_index(LinkedList* list, int index,long item){
	
	Node* old_end = list->end;
	if(list == NULL){
		fprintf(stderr," ***Error in set_at_index: list does not exist\n\n");
		return;
	}
	if(index >= list->occupancy || index < 0){
		fprintf(stderr," ***Error in set_at_index: Index out of range\n");
		return;
	}
	find_location(list,index);
	list->end->element = item;
	list->end = old_end;
}

void write_List(LinkedList* list){
	Node* iter;
	int count;
	if(is_empty_List(list)){
		fprintf(stderr,"write_List: List is empty\n");
		return;
	}
	iter = list->end;
	printf("--list contents--\n  index | item\n");
	for(count = 0;count < list->occupancy; ++count ){
			printf("     %d  |  %ld\n",count,iter->element);
			iter = iter->next;
	}
	
	printf("-----------------\n");
}
void write_reverse_List(LinkedList* list){
	Node* iter;
	int count;
	if(is_empty_List(list)){
		fprintf(stderr,"write_List: List is empty\n");
		return;
	}
	iter = list->end->pre;
	printf("--list contents--\n  index | item\n");
	for(count = list->occupancy -1;count >= 0; --count ){
			printf("     %d  |  %ld\n",count,iter->element);
			iter = iter->pre;
	}
	
	printf("-----------------\n");
}

void insert_Node(Node* this_Node,long item){
	
	Node* working;
	this_Node = this_Node->pre;

	working = (Node*)malloc(sizeof(Node));
	working->element = item;

	working->next = this_Node->next;
	working->pre = this_Node;
	this_Node->next->pre = working;
	this_Node->next = working;

}
long remove_Node(Node* this_Node){

	long item_to_return = this_Node->element;
	this_Node->pre->next = this_Node->next;
	this_Node->next->pre = this_Node->pre;
	free(this_Node);
	return item_to_return;
}
long view_Node(Node* this_Node){
	return this_Node->element;
}