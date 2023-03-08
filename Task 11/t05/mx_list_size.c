#include "list.h"

int mx_list_size(t_list *list){
	if (list == NULL){
		return 0;
	}
	int time = 0;
	while (list) {
	list = list->next;
	time++;
	}
	return time;
}
