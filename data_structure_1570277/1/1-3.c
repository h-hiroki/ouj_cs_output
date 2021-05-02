#include "stdio.h"
#include "stdlib.h"

struct Student
{
    int id;
    char grade;
    float average;
};
typedef struct Student STUDENT_TYPE;

int main ()
{
    STUDENT_TYPE a[5];

    a[0].id = 100;
    a[0].grade = 'A';
    a[0].average = 510.20;

    a[1].id = 200;
    a[1].grade = 'B';
    a[1].average = 410.20;

    a[2].id = 300;
    a[2].grade = 'C';
    a[2].average = 310.20;

    for (int i = 0; i < 3; ++i) {
        printf("%d ", a[i].id);
        printf("%c ", a[i].grade);
        printf("%3.2f \n", a[i].average);
    }

    return 0;
}