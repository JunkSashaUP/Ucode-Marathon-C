#include "list.h"

void mx_push_back(t_list **list, void *data){
	if (*list == NULL || list == NULL){
		*list = mx_create_node(data);
		return;
	}
	t_list *new_node = *list;
	while (new_node -> next){
		new_node = new_node -> next;
	}
	new_node -> next = mx_create_node(data);
}
