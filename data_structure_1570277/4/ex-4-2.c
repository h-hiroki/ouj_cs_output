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

int linked_list_search_node(NODE_TYPE *head, int search_value)
{
    if (head == NULL) {
        return -1; // 見つからない場合
    }

    int index;
    index = 0;
    while (head != NULL) {
        if (head->data == search_value) {
            return index;
        }

        head = head->next;
        index++;
    }
}

int linked_list_length(NODE_TYPE *head)
{
    if (head == NULL) {
        return 0; // 見つからない場合
    }

    int index;
    index = 0;
    while (head != NULL) {
        head = head->next;
        index++;
    }

    return index;
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
    int searched_index;
    int linked_list_len;

    head = NULL;
    for (int i = 0; i < DATA_SIZE; ++i) {
        data = i * 10 + 1;
        printf("inserting (head): ");
        printf("%02d\n", data);
        linked_list_insert_head(&head, data);
    }
    linked_list_print(head);

    searched_index = linked_list_search_node(head, 11);
    printf("searched_index is %d \n", searched_index);

    linked_list_len = linked_list_length(head);
    printf("linked list length is %d \n", linked_list_len);
    return 0;
}