#include <time.h>
double mx_timer(void (*f)()){
	clock_t start, finish;
	start = clock();

	f();

	finish = clock();
	double timeof_f = (double)(finish - start) / 1000000;

	if (start <= 0 || finish <= 0 || finish < start){
		return -1;
	}
	return timeof_f;
}
