#include <unistd.h>
void mx_printstr(const char *s){
	int i = 0;
	int bytes = 0;
	while(s[i] != '\0'){
		i++;
		bytes++; 
	}
	write(1, s, bytes);
}
