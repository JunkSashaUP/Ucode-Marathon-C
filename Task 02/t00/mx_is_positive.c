#include <unistd.h>	
extern void mx_printstr(const char * s);
void mx_is_positive(int i){
	char *tx;
	if (i < 0){
		tx = "negative\n";
	}
	else if (i > 0){
		tx = "positive\n";
	}
	else {
		tx = "zero\n";
	}
	mx_printstr(tx);
 }
