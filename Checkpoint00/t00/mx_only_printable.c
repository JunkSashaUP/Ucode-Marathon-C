#include <unistd.h>
void mx_only_printable(void){
	for (int c = 126; c >= 32; c--){
		write(1, &c, 1);
	}
	write(1, "\n", 1 );
}
