#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"




int main(void){
	
	LinkedList* list = new_LinkedList();
	char command;
	int index;
	long item;
	printf("--Testing Linked List--\n");
	while(1){
		printf("Inter in a command: (i) to insert         (r) to remove        (w) to write\n                    (W) to reverse write  (n) to advance next  (p) to advance pre\n                    (c) to clear          (g) to get at index  (s) to set at index\n                    (q) to quit \nChoice: ");
		scanf("%c",&command);
		if(command == 'i'){
			printf("Enter index: ");
			scanf("%d",&index);
			printf("Enter item: ");
			scanf("%ld",&item);
			insert_List(list,index,item);
		}else if(command == 'r'){
			printf("Enter index: ");
			scanf("%d",&index);
			item = remove_List(list,index);
			if(item == 0){
				getchar();
				continue;
			}
			printf("Item removed: %ld\n",item);
		}else if(command == 'w'){
			write_List(list);
		}else if(command == 'W'){
			write_reverse_List(list);
		}else if(command == 'n'){
			advance_next_List(list);
		}else if(command == 'p'){
			advance_pre_List(list);
		}else if(command == 'c'){
			clear_List(list);
		}else if(command == 'g'){
			printf("Enter index: ");
			scanf("%d",&index);
			item = get_at_index(list,index);
			if(item != 0)
				printf("viewing item at %d: %ld\n",index,item);
		}else if(command == 's'){
			printf("Enter index: ");
			scanf("%d",&index);
			printf("Enter item: ");
			scanf("%ld",&item);
			set_at_index(list,index,item);
		}else if(command == 'q'){
			break;
		}else if(command == '\n'){
			continue;
		}else{
			printf("command not valid\n");
		}
		getchar();
	}
	delete_List(&list);
	
	return 0;
}
