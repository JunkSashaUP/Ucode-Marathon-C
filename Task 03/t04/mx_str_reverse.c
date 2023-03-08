extern void mx_swap_char(char *s1, char *s2);
extern int mx_strlen(const char *s);

void mx_str_reverse(char *s){
	int bytes = mx_strlen(s);
	for (int i = 0; i < bytes / 2; i++){
		mx_swap_char(&s[i], &s[bytes - i - 1]);
	}
}
