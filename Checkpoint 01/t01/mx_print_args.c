#include <unistd.h>
int main(int str, char *args[]){
	char new_line = '\n';
	if (str <= 1){

		return 0;
	}
	for (int i = 0; i < str; i++){
		int len = 0;
		while (args[i][len] != '\0'){
			len++;
		}
		write (1, args[i], len);
		write (1, &new_line, 1);
	}
	return 0;
}
