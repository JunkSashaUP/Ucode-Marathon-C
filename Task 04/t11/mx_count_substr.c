extern int mx_strlen(const char * s);
extern int mx_strncmp(const char *s1, const char *s2, int n);
extern char *mx_strchr(const char *s, int c);
extern char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub){
	int count = 0;
	if (mx_strlen(sub) == 0){
		return 0;
	}
	while (mx_strstr(str, sub) != NULL){
		str = mx_strstr(str, sub);

		for (int i = 0; i < mx_strlen(sub); i++){
			str++;
		}
		count++;
	}
	return count;	
}
