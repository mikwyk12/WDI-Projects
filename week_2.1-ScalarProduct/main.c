#include <stdio.h>


float scalar_product(float const[] , float const[], size_t, size_t);


int main() {
    float v1[] = {1,2,3,4,5};
    float v2[] = {6, 7, 8, 9, 10};
    float v3[] = {0, 2,3};
    float v4[] = {0,7, 0};

    float res1 = scalar_product(v1, v2, sizeof(v1)/sizeof(float), sizeof(v2)/sizeof(float));
    float res2 = scalar_product(v3, v4, sizeof(v3)/sizeof(float), sizeof(v4)/sizeof(float));

    printf("Scalar Product: %.2f\n", res1);
    printf("Scalar Product: %.2f\n", res2);

    return 0;
}


float scalar_product(float const v1[], float const v2[], size_t s1, size_t s2){
    if (s1 != s2) {
        printf("Error: Different size of vectors! \n");
        return -1;
    }
    else {
        float result = 0;

        for (int i = 0; i < s1; i++) {
            result += v1[i] * v2[i];
        }

        return result;
    }
}