#include <stdio.h>
#include <ctype.h>

int main ()
{
    char input_grade;
    int formatted_grade;

    printf("Please input grade (char).\n");
    scanf("%c", &input_grade);

    formatted_grade = toupper(input_grade);

    switch (formatted_grade) {
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

    printf("Your grade is %c.\n", formatted_grade);
    return 0;
}
