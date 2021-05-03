#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node NODE_TYPE;

void linked_list_print(NODE_TYPE *node)
{
    while (NULL != node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    NODE_TYPE *head;
    head = malloc(sizeof (NODE_TYPE)); // headのメモリ領域を先に確保する
    head->data = 300;
    head->next = malloc(sizeof (NODE_TYPE)); // nextのメモリ領域を先に確保する
    head->next->data = 400;
    head->next->next = malloc(sizeof (NODE_TYPE)); // nextのメモリ領域を先に確保する
    head->next->next->data = 500;
    head->next->next->next = malloc(sizeof (NODE_TYPE)); // nextのメモリ領域を先に確保する
    head->next->next->next->data = 600;
    head->next->next->next->next = NULL;

    linked_list_print(head);
    return 0;
}