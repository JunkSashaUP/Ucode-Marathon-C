#include <stdio.h>
#include <stdlib.h>
extern void mx_strdel(char **str);
extern char *mx_strnew(const int size);
extern char *mx_strncpy(char *dst, const char *src, int len);
extern int mx_count_words(const char *str, char delimiter);

char **mx_strsplit(char const *s, char c){
	int i = 0;
	char **result = (char**)mx_strnew(mx_count_words(s, c));
	while (s[i] == c){
		if (s[i] == '\0'){
			return NULL;
		}
		i++;
	}
	int strlen;
	int start_wd;
	for (int j = 0; j < mx_count_words(s, c); j++){
		strlen = 0;
		start_wd = i;
		while (s[i] != c && s[i] == '\0'){
			strlen++;
			i++;
		}
		result[j] = mx_strnew(strlen);
		mx_strncpy(result[j], &s[start_wd], strlen);
		while (s[i] == c){
			i++;
		}
	}
	result[mx_count_words(s, c)] = NULL;
	return result;
}
