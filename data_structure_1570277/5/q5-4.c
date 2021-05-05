#include "stdio.h"
#include "stdlib.h"

#define DATA_SIZE 6

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node NODE_TYPE;

void dll_print_head(NODE_TYPE *head)
{
    NODE_TYPE *temp;
    temp = head;

    if (temp == NULL) {
        printf("Double linked list is empty.\n");
        return;
    }

    printf("print (head): ");
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}

void dll_print_tail(NODE_TYPE *tail)
{
    NODE_TYPE *temp;
    temp = tail;

    if (temp == NULL) {
        printf("Double linked list is empty.\n");
        return;
    }

    printf("print (tail): ");
    while (temp->prev != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d \n", temp->data);
}

void dll_insert_head(NODE_TYPE **head, NODE_TYPE **tail, int data)
{
    NODE_TYPE *new_node;
    new_node = malloc(sizeof (NODE_TYPE));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

void dll_insert_tail(NODE_TYPE **head, NODE_TYPE **tail, int data)
{
    NODE_TYPE *new_node;
    new_node = malloc(sizeof (NODE_TYPE));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

int main()
{
    NODE_TYPE *head;
    NODE_TYPE *tail;
    int data;

    head = NULL;
    tail = NULL;

    for (int i = 0; i < DATA_SIZE; ++i) {
        data = (int) rand() % 100;
        printf("adding (head): ");
        printf("%02d\n", data);
        dll_insert_head(&head, &tail, data);
    }
    dll_print_head(head);
    dll_print_tail(tail);

    for (int i = 0; i < DATA_SIZE; ++i) {
        data = (int) rand() % 100;
        printf("adding (tail): ");
        printf("%02d\n", data);
        dll_insert_tail(&head, &tail, data);
    }
    dll_print_head(head);
    dll_print_tail(tail);

    return 0;
}