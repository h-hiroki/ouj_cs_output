#include <stdio.h>

int main()
{
    int i;

    for (int i = 0; i < 10; ++i) {
        printf("%d", i);
        if (i % 2) {
            printf(": odd\n");
        } else {
            printf(": even\n");
        }
    }

    return 0;
}