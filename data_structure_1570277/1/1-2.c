#include "stdio.h"

int main ()
{
    int array[3][4] = {
            {100, 200, 300, 400},
            {500, 600, 700, 800},
            {900, 1000, 1100, 1200}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("array[%d][%d] = %04d \n", i, j, array[i][j]);
        }
    }

    return 0;
}