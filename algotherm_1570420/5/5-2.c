#include <stdio.h>

void print_numbers(void)
{
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    print_numbers();
    print_numbers();
    print_numbers();
    return 0;
}