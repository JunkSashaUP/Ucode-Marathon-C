#include <stdlib.h>
#include <stdio.h>
char *mx_strnew(const int size){
	char *str = (char *) malloc(size + 1);

	if (str == NULL){
		return NULL;
	}
	for (int i = 0; i < size + 1; i++){
		str[i] = '\0';
	}
	return str;
}
