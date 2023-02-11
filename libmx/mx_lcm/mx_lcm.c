extern int mx_gcd(int a, int b);

int mx_lcm(int a, int b){
	if (a == 0 || b == 0 || a == b){
		return 0;
	}
	int c = (a * b) / mx_gcd(a, b);

	return c < 0 ? -c : c;
}
