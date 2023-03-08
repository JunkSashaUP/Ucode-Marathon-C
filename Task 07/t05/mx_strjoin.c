#include <stdio.h>
extern int mx_strlen(const char * s);
extern char *mx_strcpy(char *dst, const char *src);
extern char *mx_strcat(char *s1, const char *s2);
extern char *mx_strnew(const int size);
extern char *mx_strdup(const char *str);

char *mx_strjoin(char const *s1, char const *s2){
	char *s;
	if (s1 == NULL && s2 != NULL){
		s = mx_strdup(s2);
	}
	else if (s1 != NULL && s2 == NULL){
		s = mx_strdup(s1);
	}
	else if (s1 == NULL && s2 == NULL){
		return NULL;
	}
	else {
	s = mx_strdup(s1);
	s = mx_strcat(s, s2);
	}
	return s;
}
