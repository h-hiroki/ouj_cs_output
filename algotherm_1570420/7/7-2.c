#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 13

int binary_search(int array[], int num, int key)
{
    int low, mid, high;
    low = 0;
    high = num - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (key == array[mid]) {
            return mid;
        } else if (key < array[mid]) {
            high = mid - 1;
        } else if (key >= array[mid]) {
            low = mid + 1;
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
            50, 80, 150, 210, 250, 280, 330,
            470, 510, 530, 800, 900, 990
    };

    key = 800;

    print_array(array, ARRAY_SIZE);
    index = binary_search(array, ARRAY_SIZE, key);
    if (index != -1) {
        printf("Found: %d (Index: %d)\n", key, index);
    } else {
        printf("Not found: %d\n", key);
    }

    return 0;
}