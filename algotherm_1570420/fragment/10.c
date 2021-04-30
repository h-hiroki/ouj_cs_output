#include "stdio.h"

int main()
{
    int b;
    int a[5] = { 5, 4, 10, 3, 2 };

    b = 1;
    for (int i = 0; i < 5; ++i) {
        b = b * a[i];
    }

    printf("%d", b);

    return 0;
}