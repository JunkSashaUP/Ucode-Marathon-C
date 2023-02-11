#include <stdbool.h>
extern void mx_printchar(char c);
extern void mx_printint(int n);
extern bool mx_isspace(char c);
extern bool mx_isdigit(int c);
extern int mx_atoi(const char *str);

int main(int argc, char *arr[]){
	if (argc < 2){
		return 0;
	}
	for (int i = 1; i < argc; i++){
		int number = mx_atoi(arr[i]);
		for (int j = 31; j >=0; j--){
			int key = number >> j;
			if (key & 1){
				mx_printint(1);
			}
			else {
				mx_printint(0);
			}
		}
		mx_printchar('\n');
	}
	return 0;
}
