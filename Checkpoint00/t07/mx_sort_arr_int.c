void mx_sort_arr_int(int *arr, int size){
	int time;
	int a = 1;
	while(a){
		a = 0;
		for (int i = 0; i < size - 1; i++){
			if (arr[i] > arr[i+1]){
				time = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = time;
				a = 1;
			}
		}
	}
}
