#include "file_to_str.h"
char *mx_file_to_str(const char *filename){
	if (filename == NULL){
		return NULL;
	}
	int file_ch = open(filename, O_RDONLY);

	if (file_ch < 0){
		return NULL;
	}
	char tx;
	int len = 0;
	while (read(file_ch, &tx, 1)){
		len++;
	}
	if (close(file_ch) < 0){
		return NULL;
	}
	file_ch = open(filename, O_RDONLY);
	 if (file_ch < 0){
                return NULL;
        }
	char *string = mx_strnew(len);
	for (int i = 0; read(file_ch, &tx, 1); i++){
		string[i] = tx;
	}
	if (close(file_ch) < 0){
                return NULL;
        }
	return string;

}
