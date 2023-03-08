int mx_count_words(const char *str, char delimiter){
	int count = 0;
	int temp = 0;
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] == delimiter && str[i] != str[i - 1]){
			if (count == 0){
				count = 2;
			}
			else {
			count++;
			}
		}
		temp = i;
	}
	if (str[0] == delimiter){
		count--;
	}
	if (str[temp] == delimiter){
		count--;
	}
	return count;
}
