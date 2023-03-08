#include <stdbool.h>
extern void mx_printchar(char c);
extern void mx_printint(int n);
extern bool mx_isspace(char c);
extern bool mx_isdigit(int c);
extern int mx_atoi(const char *str);

int main(int str, char *arr[]){
	if (str < 2){
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < str; i++){
		int minus = 0;
		int num = 0;
		int load = 1;
		for (int j = 0; arr[i][j] != '\0'; j++){
			if (j == 0 && arr[i][j] == '-'){
				minus = 1;
				continue;
			}
			if (j == 0 && arr[i][j] == '+'){
				minus = 0;
				continue;
			}
			if (mx_isdigit(arr[i][j]) == false){
				load = 0;
				break;
			}
			num = 10 * num + (int)arr[i][j] - 48;

		}
		if (load == 1){
			if (minus == 1){
				sum -= num;
			}
			else {
				sum += num;
			}
		}
	}
	mx_printint(sum);
	mx_printchar('\n');

	return 0;
}
