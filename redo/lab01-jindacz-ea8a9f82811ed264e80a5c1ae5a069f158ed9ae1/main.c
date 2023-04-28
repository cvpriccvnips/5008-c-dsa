#include <stdio.h>

// Add your program here!
double power(double base, double n) {
	int i;
	double res = 1;
	for (i = 1; i <= n; i ++) {
		res *= base;
	}
	return res;
}

int main(){
	int i;
	for (i = 1; i <= 10; i ++) {
		double res = power(2, i);
		printf("%f \n", res);
	}
	return 0;
}
