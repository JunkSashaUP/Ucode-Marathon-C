#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)){
	if (cmp == NULL || list == NULL){
		return list;
	}
	int size_of_list = 0;
	t_list *current = list;
	while (current){
		current = current -> next;
		size_of_list++;
	}
	for (int i = 0; i < size_of_list; i++){
		current = list;
		for (int j = 0; j < size_of_list - 1; j++){
			if (cmp(current -> data, current -> next -> data)){
				void *data = current -> data;
				current -> data = current -> next -> data;
				current -> next -> data = data;
			}
			current = current-> next;
		}
	}
	return list;
}
