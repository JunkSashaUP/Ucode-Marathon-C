extern int mx_strlen(const char * s);
extern char *mx_strchr(const char *s, int c);
extern void mx_printchar(char c);
extern void mx_printstr(const char *s);

int main(int str, char *arr[]){
	int next = 0;
	for (int i = 0; arr[0][i] != '\0'; i++){
		if (arr[0][i] == '/'){
			next = i;
		}
	}	
	for (int i = next + 1; arr[0][i] != '\0'; i++){
		mx_printchar(arr[0][i]);
	}
	mx_printchar('\n');
	return str;
}
