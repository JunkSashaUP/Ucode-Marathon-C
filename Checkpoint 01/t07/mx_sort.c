#include <stdbool.h>
void mx_sort(int *arr, int size, bool (*f)(int, int)){
	for (int i = 0; i < size - 1; i++){
		int index = 1;
		for (int j = i + 1; j < size; j++){
			if (f(arr[index], arr[j])){
				index = j;
			}
		}
		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
}
