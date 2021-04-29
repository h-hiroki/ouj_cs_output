#include "stdio.h"

int factorial(int n)
{
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int i;
    i = 5;
    printf("%d! = %d\n", i, factorial(i));
    return 0;
}