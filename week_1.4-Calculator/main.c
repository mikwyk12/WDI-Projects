#include <stdio.h>

void calculator(float, char, float);


int main() {
    float n1 = 0;
    float n2 = 0;
    char oper;

    printf("---Calculator Program---\n");
    printf("-Please enter the value-\n");
    printf("---n1--operation--n2----\n");
    scanf("%f %c %f", &n1, &oper, &n2);
    calculator(n1, oper, n2);

    return 0;
}


void calculator(float a, char operation, float b) {
    switch (operation)
    {
        case '+':
            printf("= %f", a + b);
            break;

        case '-':
            printf("= %f", a - b);
            break;

        case '*':
            printf("= %f", a * b);
            break;

        case '/':
            if (b == 0) {
                printf("You can not divide by zero!");
                break;
            }
            else printf("= %f", a / b);
            break;

        default:
            printf("Error! Operator is not correct!");
    }
}
