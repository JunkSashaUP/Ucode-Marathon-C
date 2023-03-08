char *mx_strchr(const char *s, int c){
	for (const char *i = s; *i; i++){
		if (i[0] == c){
			return (char*)i;
		}
	}
	return 0;
}
