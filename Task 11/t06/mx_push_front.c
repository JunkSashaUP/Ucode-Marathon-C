#include "list.h"
void mx_push_front(t_list **list, void *data){
	if (*list == NULL || list == NULL){
		*list = mx_create_node(data);
		return;
	}
	t_list *new_node = mx_create_node(data);
	new_node->data = data;
	new_node->next = *list;
	*list = new_node;
}
