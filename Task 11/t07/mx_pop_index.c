#include "list.h"
void mx_pop_index(t_list **list, int index){
	if (*list == NULL || list == NULL){
		return;
	}
	t_list *time = *list;
	t_list *time_start = NULL;
	if (index < 0){
		*list = time->next;
		free(time);
		time = NULL;
		return;
	}
	for (int i = 0; i < index; i++){
		if (time -> next == NULL){
			break;
		}
		time_start = time;
		time = time->next;
	}
	time_start->next = time->next;
	free(time);
	time = NULL;
	return;
}
