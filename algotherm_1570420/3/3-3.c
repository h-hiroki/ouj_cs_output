#include <stdio.h>

int main()
{
    int i, j;

    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 15; ++j) {
            printf("%03d\t", i * j);
        }
        printf("\n");
    }

    return 0;
}