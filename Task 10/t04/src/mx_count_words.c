#include "../inc/header.h"

int mx_count_words(const char *str){
	bool flags = 0;
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++){
		if (mx_isspace(str[i])){
			flags = false;
		}
		else if (!flags){
			flags = true;
			count++;
		}
	}
	return count;
}
