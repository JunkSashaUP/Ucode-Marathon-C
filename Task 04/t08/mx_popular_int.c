int mx_popular_int(const int *arr, int size){
	int maxFreq = 0;
	int mostFrequent = -1; 
	for (int i = 0; i < size - 1; i++){
		int countFreq = 1;
		for (int j = 0; j < size - 1; j++){
			if (arr[j] == arr[i]){
				countFreq = countFreq + 1;
			}
		}
		if (maxFreq < countFreq){
			maxFreq = countFreq;
			mostFrequent = arr[i];
		}
		else if (maxFreq == countFreq && mostFrequent >= arr[i]){
			mostFrequent = arr[i];
		}
	}
	return mostFrequent;
}
