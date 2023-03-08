#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src){
    if (src->arr == NULL) {
        return NULL;
    }
    t_intarr temp;
    temp.size = src->size;
    temp.arr = (int *) malloc(temp.size * sizeof(int));
    if (temp.arr == NULL){
    	return NULL;
    }
    int count = 0;
    for (int i = 0; i < src->size; i++) {
        int check = -1;
        for(int j = 0; j < i; j++) {
            if(src->arr[i] == src->arr[j]) {
                check = 1;
            }
        }
        if(check == 1) { 
            continue;
        }
        temp.arr[count] = src->arr[i];
        count++;
    }
    t_intarr *result = malloc(sizeof(t_intarr *));
    result->size = count;
    result->arr = mx_copy_int_arr(temp.arr, count);
    free(temp->arr);
    temp->arr = NULL;
    return result;
}
