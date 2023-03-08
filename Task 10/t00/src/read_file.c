#include "../inc/header.h"
int main(int argc, char *argv[]){
	if (argc != 2){
		write(2, "usage: ./read_file [file_path]\n", 31);
		return -1;
	}
	int file_open = open(argv[1], O_RDONLY);
	if (file_open < 0){
		write(2, "error\n", 6);
		return -1;
	}
	char tx;
	ssize_t ref = 0;
	while (ref == read(file_open, &tx, 1) > 0){
		write(1, &tx, 1);
		if (ref < 0){
			write(2, "error\n", 6);
			return -1;
		}
	}
	close(file_open);
	return 0;
		
}
