#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a[2][3][4];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                a[i][j][k] = rand() % 100 + 1;
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                printf("[%d][%d][%d] = %d\n", i, j, k, a[i][j][k]);
            }
        }
    }

    return 0;
}