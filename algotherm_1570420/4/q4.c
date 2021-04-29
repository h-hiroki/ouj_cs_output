#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result, max, min;

    for (int i = 0; i < 1000; ++i) {
        result = rand() % 10 + 30;
        printf("%d, ", result);

        if (i == 0) {
            max = result;
            min = result;
        }
        if (max < result) {
            max = result;
        }
        if (min > result) {
            min = result;
        }
    }
    printf("\n");
    printf("max: %d\t min: %d\n", max, min);
    return 0;
}