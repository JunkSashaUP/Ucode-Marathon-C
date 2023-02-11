#include <unistd.h>
extern void mx_printchar(char c);
void mx_print_alphabet(void){
        for (int c = 97; c <= 122; c++){
        if (c >= 96 && c <= 122){
                c -= 32;
                write(1, &c, 1);
        }
	else if(c >= 64 && c <= 91){
		c += 32;
		 write(1, &c, 1);
        }
        }
          write(1, "\n", 1);
}
