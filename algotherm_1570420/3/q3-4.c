#include <stdio.h>

int main ()
{
    int i, j, k;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                printf("%d %d %d", i, j, k);
                printf("\n");
            }
        }
    }

    return 0;
}