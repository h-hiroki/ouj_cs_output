#include <stdio.h>

int main ()
{
    char grade;
    grade = 'B';

    switch (grade) {
        case 'A':
            printf("execllent\n");
            break;
        case 'B':
            printf("good\n");
            break;
        case 'C':
            printf("soso\n");
            break;
        case 'D':
            printf("barely passing\n");
            break;
        case 'E':
            printf("not passing\n");
            break;
        default:
            printf("Error: invalid character\n");
            break;
    }

    printf("Your grade is %c.\n", grade);
    return 0;
}