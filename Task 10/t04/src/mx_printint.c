#include "../inc/header.h"
void mx_printint(int n){
	char reg[55];
	int i = 0;
	long num = n;
	if (num == 0){
		mx_printchar(n + '0');
	}
	if (num < 0){
		num *= -1;
		mx_printchar('-');
	}
	while (num != 0){
		reg[i++] = (num % 10) + '0';
		num /= 10;
	}

	for (int g = i - 1; g >= 0; g--){
		mx_printchar(reg[g]);
	}
}
