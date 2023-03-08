#include "../inc/header.h"
int main(int argc, char *argv[]){
	if (argc != 3){
		mx_printerr("usage: ");
		mx_printerr(argv[0]);
		mx_printerr(" [source_file] [destination_file]\n");
		exit(-1);
	}
	int file_open = open(argv[1], O_RDONLY);
	if (file_open < 0){
		mx_printerr("mx_cp: ");
		mx_printerr(argv[1]);
		mx_printerr(": No such file or directory\n");
		exit(-1);
	}
	char tx;
	int tx_len;
	int file_read = open(argv[2], O_WRONLY | O_CREAT, 0644); 
	while ((tx_len = read(file_open, &tx, 1)) > 0){
		write(file_read, &tx, tx_len);
	}
	close(file_open);
	close(file_read);
	return 0;
}
