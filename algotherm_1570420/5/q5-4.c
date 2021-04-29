#include "stdio.h"

void foo(int n)
{
    if (n < 15) {
        foo(n + 1);
        printf("%d ", n);
    }
}

int main()
{
    foo(0);
    return 0;
}