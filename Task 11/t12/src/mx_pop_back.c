#include "../inc/list.h"

void mx_pop_back(t_list **list) {
    if (*list == NULL || list == NULL) {
        return;
    }

    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }

    t_list *temp_node = *list;

    while (temp_node->next->next != NULL) {
        temp_node = temp_node->next;
    }

    free(temp_node->next);
    temp_node->next = NULL;
    temp_node = NULL;
}
