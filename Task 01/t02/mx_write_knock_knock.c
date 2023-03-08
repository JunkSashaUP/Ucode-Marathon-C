#include <string.h>
#include <unistd.h>
void mx_write_knock_knock(void){
	const char * msg_rabbit = "Follow the white rabbit.\n";
	const char * msg_knock = "Knock, knock, Neo.\n";
	write(1, msg_rabbit, strlen(msg_rabbit));
	write(1, msg_knock, strlen(msg_knock));
}
