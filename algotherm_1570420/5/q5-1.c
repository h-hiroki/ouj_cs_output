#include "stdio.h"

float trapezoid(float a, float b, float h)
{
    float c;
    c = ((a + b) / 2.0) * h;
    return c;
}

int main()
{
    float t;
    t = trapezoid(3.0, 4.0, 5.0);
    printf("trapezoid = %f\n", t);
    t = trapezoid(5.0, 6.0, 7.0);
    printf("trapezoid = %f\n", t);

    return 0;
}