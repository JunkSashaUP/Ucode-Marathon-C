extern int mx_strlen(const char * s);
extern char *mx_strcpy(char *dst, const char *src);
extern char *mx_strnew(const int size);

char *mx_strdup(const char *str){
	int size = mx_strlen(str);
	char *s = mx_strnew(size);
	s = mx_strcpy(s, str);	
	return s;
}
