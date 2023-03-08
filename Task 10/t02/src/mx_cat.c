#include "../inc/header.h"

int main(int argc, char *argv[]){
	char tx;
	 if (argc == 1){
	 	while (read(0, &tx, 1)){
			write(1, &tx, 1);
		}
	 }
	 int file;
	 for (int i = 1; i < argc; i++){
	 	file = open(argv[i], O_RDONLY);
		if (file < 0){
			mx_printerr("mx_cat: ");
			mx_printerr(argv[i]);
			mx_printerr(": No such file or directory\n");
			exit(-1);
		}
		else {
			while (read(file, &tx, 1)){
				write(1, &tx, 1);
			}
		}
		close(file);
	 }
	 return 0;
}
