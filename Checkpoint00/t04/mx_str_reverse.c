void mx_str_reverse(char *s){
	int bytes  = 0;
	while(s[bytes] != '\0')		
	{
		bytes++;
	}
	for (int i = 0; i !=  bytes / 2; i++){
		char str = s[i];
		s[i] = s[bytes - 1 - i];
		s[bytes - 1 - i] = str;

	}
}
