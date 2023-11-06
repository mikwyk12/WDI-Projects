#include <stdio.h>
#define ROW1 2
#define COL1 3
#define ROW2 3
#define COL2 2


int main() {
    int m1[ROW1][COL1] = {{1,0,2},{-1,3,1}};
    int m2[ROW2][COL2] = {{3, 1}, {2, 1},{1,0}};
    int res[ROW1][COL2];

    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            res[i][j] = 0;
            for (int r = 0; r < ROW2; r++) {
                res[i][j] = res[i][j] + m1[i][r] * m2[r][j];
            }
        }
    }

    for (int row = 0; row < ROW1; row++) {
        for (int col = 0; col < COL2; col++)
            printf("%d\t", res[row][col]);
        printf("\n");
    }

    return 0;
}
