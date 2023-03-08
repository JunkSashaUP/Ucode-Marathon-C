#include "../inc/header.h"

void print_data(int lines, int words, int bytes, char *file){
	mx_printchar('\t');
	mx_printint(lines);
	mx_printchar('\t');
	mx_printint(words);
	mx_printchar('\t');
	mx_printint(bytes);

	if (file){
		mx_printchar(' ');
		mx_printstr(file);
	}
	mx_printchar('\n');
}

int main(int argc, char *argv[]){
	if (argc == 1){
		char *str = mx_strnew(1);
		char *s = mx_strnew(1);
		int lines = 0, words = 0, bytes = 0;
		
		while(read(0, s, 1)){
		if (*s == '\n'){
			lines++;
		}
		str = mx_strjoin(str, s);
		bytes++;
		}
		words = mx_count_words(str);
		print_data(lines, words, bytes, NULL);
		exit(EXIT_SUCCESS);
	}

	int total_lines = 0, total_words = 0, total_bytes = 0;
	for (int i = 0; i < argc; i++){
		int src = open(argv[i], O_RDWR);

		if (src == -1){
			mx_printerr("mx_wc: ");
			mx_printerr(argv[i]);
			mx_printerr(": ");
			switch (errno){
				case EISDIR:
					mx_printerr("read: ");
					break;
				case ENOENT:
					mx_printerr("open: ");
					break;
			}
			mx_printerr(strerror(errno));
			mx_printerr("\n");
		}
		else {
			char *str = mx_strnew(1), *s = mx_strnew(1);
			int lines = 0, words = 0, bytes = 0;

			while (read(src, s, 1)){
				if (*s == '\n'){
					lines++;
				}
				str = mx_strjoin(str, s);
				bytes++;
			}
			words = mx_count_words(str);
			total_words += words;
			total_lines += lines;
			total_bytes += bytes;

			print_data(lines, words, bytes, argv[i]);

			close(src);
		}
	}
	if (total_bytes && argc > 1){
		print_data(total_lines, total_words, total_bytes, "total");
	}
	return 0;
}
