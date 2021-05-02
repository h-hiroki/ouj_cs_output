#include "stdio.h"
#include "stdlib.h"

#define MAX 128
#define PUSH_SUCCESS 1
#define PUSH_FAILURE -1
#define POP_SUCCESS 2
#define POP_FAILURE -2


int peek(int stack[], int *top, int *data)
{
    if ((*top) > 0) {
        *data = stack[(*top) - 1];
        return POP_SUCCESS;
    } else {
        return POP_FAILURE;
    }
}

void stack_init(int *top)
{
    *top = 0;
}

void display(int stack[], int top)
{
    printf("STACK (%d) : ", top);
    for (int i = 0; i < top; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int push(int stack[], int *top, int data)
{
    if (*top >= MAX) {
        return PUSH_FAILURE;
    } else {
        stack[*top] = data;
        (*top) ++;
        return PUSH_SUCCESS;
    }
}

int pop(int stack[], int *top, int *data)
{
    if (*top > 0) {
        *data = stack[(*top) - 1];
        (*top) --;
        return POP_SUCCESS;
    } else {
        return POP_FAILURE;
    }
}

int main()
{
    int stack[MAX];
    int top, data;

    stack_init(&top);

    data = 300;
    printf("push: %d\n", data);
    push(stack, &top, data);
    display(stack, top);
    printf("top: %d\n", top);

    data = 400;
    printf("push: %d\n", data);
    push(stack, &top, data);
    display(stack, top);
    printf("top: %d\n", top);

    data = 500;
    printf("push: %d\n", data);
    push(stack, &top, data);
    display(stack, top);
    printf("top: %d\n", top);


    peek(stack, &top, &data);
    printf("peek: %d\n", data);

    peek(stack, &top, &data);
    printf("peek: %d\n", data);

    display(stack, top);

    pop(stack, &top, &data);
    printf("pop: %d\n", data);
    display(stack, top);
    printf("top: %d\n", top);

    pop(stack, &top, &data);
    printf("pop: %d\n", data);
    display(stack, top);
    printf("top: %d\n", top);

    return 0;
}