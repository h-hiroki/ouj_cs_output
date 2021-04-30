#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 13

int linear_search(int array[], int n, int key)
{
    for (int i = 0; i < n; ++i) {
        if (array[i] == key) {
            return i;
        }
    }

    return -1;
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main()
{
    int index, key;
    int array[ARRAY_SIZE] = {
            900, 900, 210, 50, 80, 150, 330,
            470, 510, 530, 800, 250, 280
    };

    key = 800;

    print_array(array, ARRAY_SIZE);
    index = linear_search(array, ARRAY_SIZE, key);
    if (index != -1) {
        printf("Found: %d (Index: %d)\n", key, index);
    } else {
        printf("Not found: %d\n", key);
    }

    return 0;
}