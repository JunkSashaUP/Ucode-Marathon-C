extern int mx_strlen(const char * s);
char *mx_strcat(char *s1, const char *s2){
	int p1 = mx_strlen(s1);
	int p2 = mx_strlen(s2);
	for (int i = 0; i < p2; i++){
		s1[p1 + i] = s2[i];
	}
	s1[p1 + p2] = '\0';
	return s1;
}
