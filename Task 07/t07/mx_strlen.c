#include <unistd.h>
int mx_strlen(const char * s){
	int c = 0;
	while(*s++)		
	{
		c++;
	}
	return c;
}	
