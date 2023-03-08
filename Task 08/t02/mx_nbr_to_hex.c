#include "nbr_to_hex.h"

char *mx_nbr_to_hex(unsigned long nbr){
	int i = 0;
	int len = 0;
	if (nbr == 0){
		char * result = mx_strnew(1);
		result[0] = '0';
		return result;
	}	
	char *arr = mx_strnew(55);
	while (nbr != 0){
		int temp = 0;
		temp = nbr % 16;
			if (temp < 10){
				arr[i++] = temp + 48;
			}
			else {
				arr[i++] = temp + 87;
			}
		nbr = nbr / 16;
		len++;

	}
	char *result = mx_strnew(len);
	for (int i = 0; i < len; i++){
		result[i] = arr[len - i - 1];
	}
	free(arr);
	return result;	
}
