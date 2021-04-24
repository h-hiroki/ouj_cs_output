#include <stdio.h>
#include <math.h>

int main() {

    double x = 2.0;
    float y = 3.14;
    long z = 123;

    printf("x: %f\tsqrted: %f\n", x , sqrt(x));
    printf("y: %f\tsqrted: %f\n", y , sqrtf(y));
    printf("z: %ld\tsqrted: %Lf\n", z , sqrtl(z));

    return 0;
}