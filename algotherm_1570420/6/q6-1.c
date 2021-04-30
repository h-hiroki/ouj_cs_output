#include "stdio.h"

int main()
{
    float a[5];
    float sum, avg;

    a[0] = 30.0;
    a[1] = 20.0;
    a[2] = 10.0;
    a[3] = 25.0;
    a[4] = 15.0;

    sum = 0.0;
    for (int i = 0; i < (sizeof a / sizeof a[0]); ++i) {
        sum += a[i];
    }

    avg = sum / (sizeof a / sizeof a[0]);
    printf("sum: %f\tavg: %f\n", sum, avg);

    return 0;
}