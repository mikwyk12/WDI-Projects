#include <stdio.h>


void printSpiral(int n);


int main() {
    printSpiral(4);
    return 0;
}

void printSpiral(int n) {
    int tab[n][n] = {};
    int num = 1;
    int N = n - 1;

    for (int i = 0; i < n/2; i++, N--) {
        //left to right
        for (int j = i; j <= N; j++)
            tab[i][j] = num++;

        //top to bottom
        for (int j = i+1; j <= N; j++)
            tab[j][N] = num++;

        //right to left
        for (int j = N-1; j >= i; j--)
            tab[N][j] = num++;

        //bottom to top
        for (int j = N-1; j > i; j--)
            tab[j][i] = num++;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
}
