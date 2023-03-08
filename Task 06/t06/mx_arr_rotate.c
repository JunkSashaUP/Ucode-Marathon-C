void mx_arr_rotate(int *arr, int size, int shift){
	if (shift > 0 && shift <= size){
		shift = size - shift;
	}
	else if (shift > 0){
		while (shift > size)
		shift -= size;
		shift = size - shift;
	}
	else {
		shift *= -1;
	}
	for (int i = 0; i < shift; i++){
		int temp = arr[0];
		for (int i = 0; i < size - 1; i++){
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = temp;
	}
}
