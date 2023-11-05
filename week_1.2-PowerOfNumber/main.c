#include <stdio.h>


double power_of_number(double, int);


int main() {
    int base[] = {3, 2, 4, 4};
    int exponent[] = {2, 4, 0, -1};

    for (int i = 0; i < 4; i ++) {
        double result = power_of_number(base[i], exponent[i]);
        if (result != -1) printf("%d to the power of %d is %.2lf\n", base[i],  exponent[i], result);
    }

    return 0;
}


double power_of_number(double x, int n){
    if (n < 0) {
        printf("The exponent must be a non-negative number!");
        return -1;
    }
    else {
        int i = 0;
        double result = 1;
        while (i < n) {
            result *= x;
            i++;
        }
        return result;
    }
}
