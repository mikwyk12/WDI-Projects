#include <stdio.h>
#include <math.h>


int numberOfRoots(float, float, float, float*, float*);


int main() {
    float a, b, c;
    float p1, p2;

    printf("Give the coefficients of the quadratic equation (f(x) = ax^2 + bx + c):\n");
    scanf("%f %f %f", &a, &b, &c);

    int result = numberOfRoots(a, b, c, &p1, &p2);

    switch (result) {
        case 0:
            printf("No zeros!\n");
            break;

        case 1:
            printf("One double zero!\n");
            printf("p1 = p2 = %f\n", p1);

            break;

        case 2:
            printf("Two zeros!\n");
            printf("p1 = %f,\tp2 = %f\n", p1, p2);
            break;

        default:
            printf("Something went wrong! Try again.");
            break;
    }

    return 0;
}


int numberOfRoots(float a, float b, float c, float* p1, float* p2) {
    float delta = b*b - 4*a*c;

    if (delta > 0) {
        *p1 = (-b - sqrtf(delta))/(2*a);
        *p2 = (-b + sqrtf(delta))/(2*a);

        return 2;
    }
    else if (delta == 0) {
        *p1 = -b/(2*a);
        *p2 = *p1;

        return 1;
    }
    else return 0;
}
