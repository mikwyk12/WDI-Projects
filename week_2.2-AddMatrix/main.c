#include <stdio.h>
#define ROW 3
#define COL 2


int main() {
    int m1[ROW][COL] = {{1,2}, {3,4}, {5,6}};
    int m2[ROW][COL] = {{9,8}, {7,6}, {5,4}};
    int result[ROW][COL];

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            result[row][col] = m1[row][col] + m2[row][col];
        }
    }

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) printf("%d\t", result[row][col]);
        printf("\n");
    }

    return 0;
}
