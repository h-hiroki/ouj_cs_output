#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 500000

int main ()
{
    int *array;

    array = malloc(sizeof (int) * ARRAY_SIZE);

    if (array == NULL) {
        fprintf(stderr, "Error: malloc() \n");
        exit (-1);
    }

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % 1000;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}