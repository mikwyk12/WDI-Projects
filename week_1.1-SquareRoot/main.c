#include <stdio.h>
#include <math.h>

int main() {
    double number = 0;

    do {
        printf("Enter the number:");
        scanf("%lf", &number);
        printf("Square root of a number: %f\n", sqrt(number));
    } while(number != 0 && number != 1);

    return 0;
}
