double mx_pow(double n, unsigned int pow){
	double doub = n;
	for (unsigned int i = 1; i < pow; i++){
		doub = doub * n;
	}
	if (pow == 0){
		return 1;
	}
	else {
		return doub;
	}
}
