#include "list.h"

void mx_push_index(t_list **list, void *data, int index){
	if (*list == NULL || list == NULL){
		return;
	}
	if (index < 1){
		mx_push_front(list, data);
		return;
	}
	int size_list = 0;
	t_list *temp_count = *list;
	while (temp_count){
		temp_count = temp_count->next;
		size_list++;
	}
	if (index >= size_list){
		mx_push_back(list, data);
		return;
	}
	t_list *time = *list;
	t_list *time_start = NULL;
	for (int i = 0; i < index; i++){
		time_start = time;
		time = time->next;
	}
	time_start->next = mx_create_node(data);
	time_start->next->next = time;
}
