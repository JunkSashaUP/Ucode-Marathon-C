#include "get_address.h"

char *mx_get_address(void *p){
	unsigned long src = (unsigned long)&p;
	char* str = mx_nbr_to_hex(src);
	int len = mx_strlen(str);

	char* result = (char*)malloc(len + 2);
	*result++ = '0';
	*result++ = 'x';

	mx_strcpy(result, str);
	free(str);
	result -= 2;
	return result;
}
