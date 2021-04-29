#include <stdio.h>

void add_pass_by_value(int i)
{
    i = i + 1;
    // 引数で渡ってきた値がiになっているので、呼び出し元の数値は変わらない
}

void add_pass_by_reference(int *i)
{
    *i = *i + 1;
    // 引数で渡ってきた値のポインタを利用するので呼び出し元の数値は変更される
}

int main()
{
    int a;

    a = 10;
    add_pass_by_value(a);
    printf("%d\n", a);

    add_pass_by_reference(&a);
    printf("%d\n", a);

    return 0;
}