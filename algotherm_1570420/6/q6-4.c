#include "stdio.h"
#include "string.h"

int main()
{
    char s0[] = "aaaaa";
    char s1[] = "bbbbb";
    char s2[] = "aaaaaaa";

    char str1[4];
    char str2[4];

    printf("strncmp(str1, str2, 3)\n");

    printf("[%s]\t[%s]\t(%d)\n", strncpy(str1, s0, 3), strncpy(str2, s0, 3), strncmp(s0, s0, 3));
    printf("[%s]\t[%s]\t(%d)\n", strncpy(str1, s0, 3), strncpy(str2, s1, 3), strncmp(s0, s1, 3));
    printf("[%s]\t[%s]\t(%d)\n", strncpy(str1, s0, 3), strncpy(str2, s2, 3), strncmp(s0, s2, 3));
    printf("[%s]\t[%s]\t(%d)\n", strncpy(str1, s1, 3), strncpy(str2, s1, 3), strncmp(s1, s1, 3));
    printf("[%s]\t[%s]\t(%d)\n", strncpy(str1, s1, 3), strncpy(str2, s2, 3), strncmp(s1, s2, 3));
    printf("[%s]\t[%s]\t(%d)\n", strncpy(str1, s2, 3), strncpy(str2, s2, 3), strncmp(s2, s2, 3));

    return 0;
}