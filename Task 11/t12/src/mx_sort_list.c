#include "../inc/list.h"

bool cmp(void *a, void *b) {
    if (mx_strcmp_new((char*)(a), (char*)(b)) > 0) return true;
    return false;
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (cmp == NULL || list == NULL) return list;
    t_list *curr = list;
    int count = 0;
    while (curr) {
        curr = curr -> next;
        count++;
    }

    for (int i = 0; i < count; i++) {
        curr = list;
        for (int j = 0; j < count - 1; j++) {
            if (cmp(curr -> data, curr -> next -> data)) {
                void *data = curr -> data; 
                curr -> data = curr -> next -> data; 
                curr -> next -> data = data;     
            }
            curr = curr -> next;
        }
    }
    return list;
}
