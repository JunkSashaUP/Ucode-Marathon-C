#include <stdio.h>
extern int mx_strlen(const char * s);
extern char *mx_strcpy(char *dst, const char *src);
extern char *mx_strcat(char *s1, const char *s2);
extern char *mx_strnew(const int size);
extern char *mx_strdup(const char *str);

char *mx_strjoin(char const *s1, char const *s2){
	char *s;
	if (s1 == NULL && s2 == NULL){
		return NULL;
	}
	if (s1 == NULL){
		return mx_strdup(s2);
	}
	if (s2 == NULL){
		return mx_strdup(s1);
	}
	char *s = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
	s = mx_strdup(mx_strcat(mx_strdup(s1), mx_strdup(s2)));
	return s;
}
