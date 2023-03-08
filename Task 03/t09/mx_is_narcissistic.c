#include <stdbool.h>
extern double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num){
	int time = 0;
	int number = num;
	int temp = num;
	int sum = 0;
	if (num <= 0){
		return false;
	}
	while (number != 0){
		time += 1;
		number /= 10;
	}
	for (int i = 0; i < time; i++){
		sum += mx_pow(temp % 10, time);
		temp = temp / 10;
	}
	return sum == num ? true : false;
}
