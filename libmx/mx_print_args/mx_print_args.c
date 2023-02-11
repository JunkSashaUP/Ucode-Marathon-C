extern int mx_strlen(const char * s);
extern void mx_printchar(char c);
extern void mx_printstr(const char *s);

int main(int str, char *args[]){
	if (str < 2){
		return 0;
	}
	for (int i = 1; i < str; i++){
		mx_printstr(args[i]);
		mx_printchar('\n');
	}
	return 0;
}
