extern int mx_strlen(const char * s);
extern char *mx_strchr(const char *s, int c);
extern int mx_strncmp(const char *s1, const char *s2, int n);

char *mx_strstr(const char *s1, const char *s2){
	while (*s1 != '\0'){
		if (!mx_strncmp(s1, s2, mx_strlen(s2))){
			return (char *)s1;
		}
		s1++;	
	}
	return 0;
}
