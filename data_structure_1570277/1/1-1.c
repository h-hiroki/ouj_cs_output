#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 10

int main ()
{
    int a[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        a[i] = rand() % 1000;
    }

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%03d ", a[i]);
    }
    printf("\n");

    return 0;
}