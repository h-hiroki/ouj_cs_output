#include <stdio.h>

int main ()
{
    int x, y;

    printf("============== inputs.\n");

    printf("Please input X (integer).\n");
    scanf("%d", &x);
    printf("Please input Y (integer).\n");
    scanf("%d", &y);

    printf("============== outputs.\n");

    printf("X = %d\n", x);
    printf("Y = %d\n", y);

    if (x > y)
        printf("X is greater than Y.\n");
    else
        printf("Y is greater than X.\n");

    return 0;
}