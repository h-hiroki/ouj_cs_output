#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, count, points;
    double x, y, q, pi;

    for (j = 1; j < 10; ++j) {
        points = 1;
        count = 0;
        points = points * pow(10, j); // powはべき乗

        for (i = 0; i < points ; ++i) {
            x = (double) rand() / ((double) RAND_MAX + 1.0); // 0以上1未満の乱数を生成
            y = (double) rand() / ((double) RAND_MAX + 1.0);
            q = sqrt((x * x) + (y * y)); // xとyの2点間の距離を求める

            if (q <= 1.0) { // 距離が1以下だったら円の中に入っているのでカウントをインクリメントする
                count++;
            }
        }

        pi = (double) count / (double) points * 4.0;
        printf("circle: %10d\t", count);
        printf("square: %10d\t", points);
        printf("PI: %f (%+f)\n", pi, (pi - M_PI));
    }

    return 0;
}