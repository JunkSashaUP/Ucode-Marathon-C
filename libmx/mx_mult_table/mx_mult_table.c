#include <stdbool.h>
extern void mx_printchar(char c);
extern void mx_printint(int n);
extern bool mx_isspace(char c);
extern bool mx_isdigit(int c);
extern int mx_atoi(const char *str);
extern int mx_strlen(char c);

int main(int argc, char *arr[]){
	if (argc != 3){
		return 0;
	}
	int arg1 = mx_atoi(arr[1]);
	int arg2 = mx_atoi(arr[2]);

	if (arg1 < 1 || arg2 < 1){
		return 0;
	}
	if (arg1 > 9 || arg2 > 9 ){
		return 0;
	}
	if (arg1 > arg2){
		int temp = arg1;
		arg1 = arg2;
		arg2 = temp;
	}
	for (int i = arg1; i <= arg2; i++){
		for (int j = arg1; j <= arg2; j++){
			mx_printint(i * j);
			if (j != arg2){
				mx_printchar('\t');
			}
		}
		mx_printchar('\n');
	}
	return 0;
}
