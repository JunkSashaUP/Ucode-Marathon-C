#include <stdlib.h>
#include <stdbool.h>
extern void mx_strdel(char **str);
extern int mx_strlen(const char * s);
extern char *mx_strnew(const int size);
extern char *mx_strncpy(char *dst, const char *src, int len);
extern bool mx_isspace(char c);

char *mx_strtrim(const char *str){
	if (str == NULL){
		return NULL;
	}	
	int start = 0;
	while (mx_isspace(str[start])){
		start++;
	}
	int end = mx_strlen(str) - 1;

	while (mx_isspace(str[end])){
		end--;
	}
	char *temp = mx_strnew(mx_strlen(str));
	temp = mx_strncpy(temp, str, mx_strlen(str));
	char *count = mx_strnew(end - start + 1);
	int j = 0;
	for (int i = start; i <= end; i++){
		count[j] = temp[i];
		j++;
	}
	mx_strdel(&temp);

	return count;
}
