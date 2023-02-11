extern int mx_strlen(const char * s);
extern void mx_printchar(char c);
extern void mx_printint(int n);
extern void mx_printstr(const char *s);

int main(int str, char *arr[]){
	mx_printstr(arr[0]);
	mx_printchar('\n');
	mx_printint(str);
	mx_printchar('\n');

	return 0;
}
