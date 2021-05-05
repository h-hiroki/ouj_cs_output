#include "stdio.h"
#include "stdlib.h"

#define STACK_UNDERFLOW (-1)
#define DATA_SIZE 6

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE_TYPE;

void stack_push(NODE_TYPE **head, int data)
{
    NODE_TYPE *new_node;
    new_node = malloc(sizeof (NODE_TYPE));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int stack_pop(NODE_TYPE **head)
{
    int data;
    NODE_TYPE *temp;

    if (*head == NULL) {
        return STACK_UNDERFLOW;
    }

    data = (*head)->data;
    temp = (*head);
    *head = (*head)->next;
    free(temp);
    return data;
}

void stack_print(NODE_TYPE *head)
{
    if (head == NULL) {
        printf("stack is empty.\n");
        return;
    }

    printf("stack [ ");
    while (head != NULL) {
        printf("%02d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

int main()
{
    NODE_TYPE *stack;
    int data;

    stack = NULL;
    for (int i = 0; i < DATA_SIZE; ++i) {
        data = (int) rand() % 100;
        printf("push: ");
        printf("%02d\n", data);
        stack_push(&stack, data);
    }
    stack_print(stack);
    for (int i = 0; i < DATA_SIZE / 2; ++i) {
        printf("pop: ");
        data = stack_pop(&stack);
        printf("%02d\n", data);
    }
    stack_print(stack);
    return 0;
}