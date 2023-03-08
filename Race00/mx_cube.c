extern void mx_printchar(char c);
void mx_cube(int n){
	if (n < 2){
		return;
	}
	for (int i = 0; i < n / 2 + 1 ; i++){
		mx_printchar(' ');
	}
	mx_printchar('+');
	for (int i = 0; i < 2 * n; i++){
		mx_printchar('-');
	}
	mx_printchar('+');
	mx_printchar('\n');	

	for (int i = 0; i < n / 2; i++){
		for (int j = 0; j < n / 2 - i; j++){
			mx_printchar(' ');
		}
		mx_printchar('/');
		for (int j = 0; j < n * 2; j++){
			mx_printchar(' ');
		}
		mx_printchar('/');
		for (int j = 0; j < i; j++){
			mx_printchar(' ');
		}
		mx_printchar('|');
		mx_printchar('\n');
	}
	mx_printchar('+');
	for (int i = 0; i < 2 * n; i++){
		mx_printchar('-');
	}
	mx_printchar('+');
	for (int i = 0; i < n / 2; i++){
		mx_printchar(' ');
	}
	mx_printchar('|');
	mx_printchar('\n');
	
	for (int i = 0; i < n - n / 2; i++){
		mx_printchar('|');
		for (int j = 0; j < n * 2; j++){
			mx_printchar(' ');
		}
		mx_printchar('|');
		for (int j = 0; j < n / 2; j++){
			mx_printchar(' ');
		}
		if (i == n - n / 2 - 1){
			mx_printchar('+');
		}
		else {
			mx_printchar('|');
		}
	mx_printchar('\n');
	}
	for (int i = 0; i < n / 2; i++){
		mx_printchar('|');
		for (int j = 0; j < n * 2; j++){
			mx_printchar(' ');
		}	
		mx_printchar('|');
		for (int j = 0; j < n / 2 - 1 - i; j++){
			mx_printchar(' ');
		}
	mx_printchar('/');
	mx_printchar('\n');
	}

	mx_printchar('+');
		for (int i = 0; i < n * 2; i++){
			mx_printchar('-');
		}
	mx_printchar('+');
	mx_printchar('\n');	
}
