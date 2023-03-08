#include <stdlib.h>
static char *mx_strnew(const int size){
	char *str = (char *) malloc(size + 1);

	if (str == NULL){
		return NULL;
	}
	for (int i = 0; i < size + 1; i++){
		str[i] = '\0';
	}
	return str;
}
static char *mx_strcpy(char *dst, const char *src){
	for (int i = 0; src[i] != '\0'; i++){
		dst[i] = src[i];
	}
	return dst += '\n';
}
char *mx_strdup(const char *str){
	if (str == NULL){
		return NULL;
	}
	int strlen = 0;
	while (str[strlen] != '\0'){
		strlen++;
	}
	char *result = mx_strnew(strlen);
	mx_strcpy(result, str);
	return result;
}
