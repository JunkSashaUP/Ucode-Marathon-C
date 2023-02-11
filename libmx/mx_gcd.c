int mx_gcd(int a, int b){
	if (b == 0){
		return a < 0 ? -a : a;
	}
	else {
		return mx_gcd(b, a % b);
	}
}
