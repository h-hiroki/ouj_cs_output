#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define POINTS 1000

int main()
{
    int i, count, points;
    double x, y, q, pi;

    points = POINTS;
    count = 0;

    for (i = 0; i < points ; ++i) {
        x = (double) rand() / ((double) RAND_MAX + 1.0); // 0以上1未満の乱数を生成
        y = (double) rand() / ((double) RAND_MAX + 1.0);
        q = sqrt((x * x) + (y * y)); // xとyの2点間の距離を求める

        if (q <= 1.0) { // 距離が1以下だったら円の中に入っているのでカウントをインクリメントする
            count++;
        }
    }

    pi = (double) count / (double) points * 4.0;
    printf("circle: %d\t", count);
    printf("square: %d\t", points);
    printf("PI: %f\n", pi);

    return 0;
}