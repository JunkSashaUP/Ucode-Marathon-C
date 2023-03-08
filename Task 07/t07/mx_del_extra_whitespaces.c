#include <stdbool.h>
#include <stdlib.h>
extern void mx_strdel(char **str);
extern int mx_strlen(const char * s);
extern char *mx_strnew(const int size);
extern char *mx_strncpy(char *dst, const char *src, int len);
extern bool mx_isspace(char c);
extern char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str){
	if (str == NULL){
		return NULL;
	}
	int time = 0;
	bool true_sp = false; 
	for (int i = 0; i < mx_strlen(str); i++){
		if (!mx_isspace(str[i])){
			time++;
			true_sp = false;
		}
		else if (mx_isspace(str[i] && true_sp == false)){
			time++;
			true_sp = true;
		}
	}
	if (time < 1){
		return NULL;
	}	
	char *str2 = mx_strnew(time);
	if (mx_strlen(str2) == 1 && mx_isspace(str2[0])){
		mx_strdel(&str2);
		return NULL;
	}

	true_sp = false;
	int index = 0;

	for (int i = 0; i < mx_strlen(str); i++){
		if (!mx_isspace(str[i])){
			str2[index] = str[i];
			index++;
			true_sp = false;
		}
		else if (mx_isspace(str[i]) && true_sp == false){
			str2[index] = ' ';
			index++;
			true_sp = true;
		}
	}
	str2 = mx_strtrim(str2);
	return str2;
}
