#include "../inc/list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)){
	t_list *temp;
	t_list *temp_curr = *list;

	if ((temp = (*list)->next)){
		while (temp->next){
			if (cmp(temp->data, del_data)){
				temp_curr->next = temp->next;
				free(temp);
				temp = temp_curr->next;
			}
			else{
				temp_curr = temp_curr->next;
				temp = temp->next;
			}
		}
		if(cmp(temp->data, del_data)){
			temp_curr->next = NULL;
			free(temp);
		}
		temp = *list;
		if (cmp(temp->data, del_data)){
			(*list) = (*list)->next;
			free(temp);
		}
	}
	else {
		if(cmp(temp_curr->data, del_data)){
			free(*list);
		}
	}
}
