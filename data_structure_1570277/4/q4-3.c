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

int linked_list_delete_tail(NODE_TYPE **head)
{
    int data;
    NODE_TYPE *temp;
    NODE_TYPE *prev;
    if (*head == NULL) {
        return -1; // 末尾のデータが無い場合
    }

    temp = *head;
    prev = *head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    data = temp->data;

    if ((*head)->next == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);

    return data;
}

void linked_list_insert_tail(NODE_TYPE **head, int data)
{
    NODE_TYPE *new_node;
    NODE_TYPE *temp;
    new_node = malloc(sizeof (NODE_TYPE));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        temp = *head; // 最初のノードを取得する
        while(temp->next != NULL) { // nextが存在しないノード(挿入前の最後のノード)を取得する
            temp = temp->next;
        }
        temp->next = new_node; // 挿入前の最後のノードに新しいノードをリンクさせる
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
        printf("inserting (tail): ");
        printf("%02d\n", data);
        linked_list_insert_tail(&head, data);
    }
    linked_list_print(head);

    for (int i = 0; i < DATA_SIZE / 2; ++i) {
        printf("deleting (tail): ");
        data = linked_list_delete_tail(&head);
        printf("%02d\n", data);
    }
    linked_list_print(head);

    return 0;
}
