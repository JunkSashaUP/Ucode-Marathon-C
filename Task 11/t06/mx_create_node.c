#include "list.h"
t_list *mx_create_node(void *data){
	if (!data){
		return NULL;	
	}
	t_list *node = (t_list*)malloc(16);
	node->data = data;
	node->next = NULL;
	return node;
}
