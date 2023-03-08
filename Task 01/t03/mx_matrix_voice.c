#include <unistd.h>
void mx_matrix_voice(void){	
	write(1, "\007", 1);
	write(1, "\045", 1);
	write(1, "\012", 1);
}
