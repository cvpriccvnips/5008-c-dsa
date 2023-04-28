#include <stdio.h>

double power(double base, double n) {
    double result = 1;
    int i;
    for (i = 0; i < n; i += 1) {
        result *= base;
    }
    return result;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int i;
    for (i = 1; i <= 10; i += 1) {
        double result = power(2, i);
        printf("2 to the power of %d is %lf\n", i, result);
    }
    
    int a = 17;
    int b = -4;
    printf("a:%d, b: %d\n",a,b);
    swap(&a, &b);
    printf("a:%d, b: %d\n",a,b);

    return 0;
}