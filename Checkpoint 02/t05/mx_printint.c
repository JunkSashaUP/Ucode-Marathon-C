#include <unistd.h>

void mx_printint(int n) {
    int temp = 0;
    if(n == 0) {
        temp = 48;
        write(1, &temp, 1);
        return;
    }
    if( n < 0) {
        temp = 45;
        write(1, &temp, 1);
        n *= -1;
    }
    int start_n = n;
    int i = 0;
    while(start_n != 0) {
        start_n = start_n / 10;
        i++;
    }
    int arr[i];
    int count_arr = 0;
    while(n != 0) { 
        arr[count_arr] = n % 10;
        n = n / 10;
        count_arr++;
    }
    for(int j = count_arr - 1; j >= 0; j--) {
        temp = arr[j] + 48;
        write(1, &temp, 1);
    }
}
