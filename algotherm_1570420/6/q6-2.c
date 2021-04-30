#include "stdio.h"

int main()
{
    int x[10][10];

    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            x[i][j] = i * j;
        }
    }

    for (int i = 1; i < 10; ++i) {
        printf("%dの段\t", i);
        for (int j = 1; j < 10; ++j) {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }

    return 0;
}