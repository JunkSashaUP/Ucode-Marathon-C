#include <stdlib.h>
int *mx_copy_int_arr(const int *src, int size){
	if (src == NULL){
		return NULL;
	}
	int *arr = malloc(size * 4);

	for (int i = 0; i < size; i++){
		arr[i] = src[i];
	}
	return arr;
}
