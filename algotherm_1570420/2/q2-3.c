#include <stdio.h>

int main ()
{
    int a = 3;

    if (a <= 2) {
        printf("A\n");
    } else if (a <= 4) {
        printf("B\n");
    } else {
        printf("ERROR: invalid number\n");
    }

    return 0;
}