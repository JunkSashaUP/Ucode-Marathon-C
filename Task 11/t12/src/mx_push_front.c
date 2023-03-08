#include "../inc/list.h"

void mx_push_front(t_list **list, void *data) {
    if (*list == NULL || list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    t_list *temp = mx_create_node(data);
    temp->data = data;
    temp->next = *list;
    *list = temp;  
}
