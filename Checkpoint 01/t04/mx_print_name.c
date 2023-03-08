#include <unistd.h>
static void mx_printint(int n){
	int temp = 48;
	if (n == 0){
		temp = 48;
		write(1, &temp, 1);
		return;
	}
	if (n < 0){
		temp = 45;
		write(1, &temp, 1);
		n *= -1;
	}
	int new_num = n;
	int counter = 0;
	while (new_num != 0){
		new_num = new_num / 10;
		counter++;
	}
	int arr[counter];
	int count_arr = 0;
	while (n != 0){
		arr[count_arr] = n % 10;
		n /= 10;
		count_arr++;
	}
	for (int g = count_arr - 1; g >= 0; g--){
		temp = arr[g] + 48;
		write(1, &temp, 1);
	}
}
int main(int str, char * args[]){
	int i = 0;
	char new_line = '\n';
	for (; args[0][i] != '\0'; i++){
	
	}
	write(1, args[0], i);
	write(1, &new_line, 1);
	mx_printint(str);
	write(1, &new_line, 1);
	return 0;
}
