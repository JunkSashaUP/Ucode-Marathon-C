extern int mx_strlen(const char * s);
extern void mx_printchar(char c);
extern void mx_printstr(const char *s);
extern int mx_strcmp(const char *s1, const char *s2);

int main(int str, char *arr[]){
	if (str < 2){
		return 0;
	}
	for (int i = 0; i < str - 1; i++){
		for (int j = i + 1; j < str; j++){
			if (mx_strcmp(arr[i], arr[j]) > 0){
				char *temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 1; i < str; i++){
		mx_printstr(arr[i]);
		mx_printchar('\n');
	}
	return 0;
}
