#include <unistd.h>
void mx_printint(int n){
	int num = 0;
	int number = n;
	if (n == 0){
		num = 48;
		write(1, &num, 1);
	}
	if (n < 0){
		num = 45;
		write(1, &num, 1);
		n *= -1;
	}
	int i = 0;
	while (number != 0){
		number /= 10;
		i++;
	}
	int arr[i];
	int cout = 0;
	while (n != 0){
		arr[cout] = n % 10;
		n /= 10;
		cout++;
	}
	for (int g = cout - 1; g >= 0; g--){
		num = arr[g] + 48;
		write(1, &num, 1);
	}
}
