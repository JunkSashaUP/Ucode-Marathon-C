int mx_factorial_rec(int n){
	if (n < 0 || n > 12){
		return 0;
	}
	if (n >= 1){
		return n * mx_factorial_rec(n - 1);
	}
	else {
		return 1;
	}
}
