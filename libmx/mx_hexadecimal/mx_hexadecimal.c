#include <unistd.h>
extern void mx_printchar(char c);
void mx_hexadecimal(void){	
	for (int c = 48; c <= 57; c++){
	mx_printchar(c);
	}	
	for (int c = 65; c <= 70; c++){
        mx_printchar(c);
        }
	write(1, "\n", 1);
}
