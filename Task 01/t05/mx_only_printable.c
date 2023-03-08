#include <unistd.h>
extern void mx_printchar(char c);
void mx_only_printable(void){
	for (int c = 126; c >= 32; c--){
		mx_printchar(c);
	}
		write(1, "\n", 1);
}
