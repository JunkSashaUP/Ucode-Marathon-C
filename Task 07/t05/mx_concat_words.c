#include <stdlib.h>
extern char *mx_strcpy(char *dst, const char *src);
extern char *mx_strcat(char *s1, const char *s2);
extern char *mx_strnew(const int size);
extern char *mx_strdup(const char *str);
extern void mx_strdel(char **str);
extern char *mx_strjoin(char const *s1, char const *s2);
extern int mx_strlen(const char * s);

char *mx_concat_words(char **words){
	if (words == NULL){
		return NULL;
	}

	char *result = mx_strdup(words[0]);

	for (int i = 0; words[i] != NULL; i++){
		char * str = mx_strjoin(result, " ");
		mx_strdel(&result);
		result = mx_strjoin(str, words[i]);
		mx_strdel(&str);
	}
	return result;
}
