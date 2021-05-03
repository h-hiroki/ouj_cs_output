#include "stdio.h"
#include "stdlib.h"

#define NOT_FOUND (-1)
#define DATA_SIZE 6

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE_TYPE;

void linked_list_insert_head(NODE_TYPE **head, int data)
{
    NODE_TYPE *new_node;
    new_node = malloc(sizeof (NODE_TYPE));
    new_node->data = data;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

void linked_list_print(NODE_TYPE *node)
{
    while (NULL != node) {
        printf("%02d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    NODE_TYPE *head;
    int data;

    head = NULL;
    for (int i = 0; i < DATA_SIZE; ++i) {
        data = (int) rand() % 100;
        printf("inserting (head): ");
        printf("%02d\n", data);
        linked_list_insert_head(&head, data);
    }
    linked_list_print(head);
    return 0;
}