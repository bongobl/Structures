#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"


ArrayList* new_ArrayList(){
	ArrayList* working = (ArrayList*)malloc(sizeof(ArrayList));
	working->the_array = (long*)malloc(0);
	working->occupancy = 0;
	working->arraySize = 0;
	return working;
}
void delete_List(ArrayList** list_pp){

	ArrayList* list_in_caller;
	if(*list_pp == NULL){
		fprintf(stderr," ***Error in delete_List: list does not exist\n\n");
		return;
	}
	list_in_caller = *list_pp;
	free(list_in_caller->the_array);
	free(list_in_caller);
	*list_pp = NULL;
}
int is_empty_List(ArrayList* list){
	if(list == NULL){
		fprintf(stderr," ***Error in is_empty_List: list does not exist\n\n");
		return 1;
	}
	if(list->occupancy == 0){
		return 1;
	}
	return 0;
}
void clear_List(ArrayList* list){
	
	if(list == NULL){
		fprintf(stderr," ***Error in clear_List: list does not exist\n\n");
		return;
	}
	list->occupancy = 0;
	checkToReallocate(list);
}
void insert_List(ArrayList* list,int index,long item){
	
	int iter;

	if(list == NULL){
		fprintf(stderr," ***Error in insert_List: list does not exist\n\n");
		return;
	}
	if(index > list->occupancy || index < 0){
		fprintf(stderr," ***Error in insert_List: Index out of range\n\n");
		return;
	}
	++list->occupancy;
	checkToReallocate(list);
	
	for(iter = list->occupancy - 2; iter >= index; --iter){
		
		list->the_array[iter+1] = list->the_array[iter];
	}
	
	list->the_array[index] = item;
	

}

long remove_List(ArrayList* list, int index){
	
	long item_to_return;
	long iter;

	if(list == NULL){
		fprintf(stderr," ***Error in remove_List: list does not exist\n\n");
		return 0;
	}
	if(is_empty_List(list)){
		fprintf(stderr,"remove_List: List is empty\n");
		return 0;
	}
	if(index >= list->occupancy || index < 0){
		fprintf(stderr," ***Error in remove_List: Index out of range\n");
		return 0;
	}
	
	item_to_return = list->the_array[index];
	for(iter = index; iter < list->occupancy - 1; ++iter){
		list->the_array[iter] = list->the_array[iter+1];
	}
	--list->occupancy;
	checkToReallocate(list);
	return item_to_return;

}
int checkToReallocate(ArrayList* list){
	
	int newSize;


	if(list->occupancy % 5 == 0){
		newSize = list->occupancy;
	}else{
		newSize = (int)((list->occupancy / 5.0) + 1) * 5.0;
	}
	if(newSize != list->arraySize){
		list->arraySize = newSize;
		list->the_array = (long*)realloc(list->the_array, newSize * sizeof(long));
	}
	return newSize;
}
void write_List(ArrayList* list){
	int iter;

	if(list == NULL){
		fprintf(stderr," ***Error in write_List: list does not exist\n\n");
		return;
	}

	printf("--list contents--\n  index | item\n");
	for(iter = 0;iter < list->occupancy; ++iter){
		printf("     %d  |  %ld\n",iter,list->the_array[iter]);
	}
	printf("-----------------\n");
}
long get_at_index(ArrayList* list,int index){

	if(list == NULL){
		fprintf(stderr," ***Error in get_at_index: list does not exist\n\n");
		return 0;
	}
	if(index >= list->occupancy || index < 0){
		fprintf(stderr," ***Error in get_at_index: Index out of range\n");
		return 0;
	}
	return list->the_array[index];
}
void set_at_index(ArrayList* list, int index,long item){
	if(list == NULL){
		fprintf(stderr," ***Error in set_at_index: list does not exist\n\n");
		return;
	}
	if(index >= list->occupancy || index < 0){
		fprintf(stderr," ***Error in set_at_index: Index out of range\n");
		return;
	}
	list->the_array[index] = item;
}
