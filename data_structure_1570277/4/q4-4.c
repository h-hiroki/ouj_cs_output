#include "stdio.h"
#include "stdlib.h"
#define DATA_SIZE 10

struct node {
    int data;
    struct node *next;
};
typedef struct node NODE_TYPE;

struct linked_list {
    NODE_TYPE *head;
    NODE_TYPE *tail;
    NODE_TYPE *current;
};
typedef struct linked_list LINKED_LIST;

void linked_list_insert_node_h(LINKED_LIST *list, int data)
{
    NODE_TYPE *new_node;
    new_node = malloc(sizeof (NODE_TYPE));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) { // 1つもノードが存在しない場合
        list->tail = new_node;
    } else { // 他にnodeがある場合
        new_node->next = list->head;
    }
    list->head = new_node;
}

void linked_list_insert_node_t(LINKED_LIST *list, int data)
{
    NODE_TYPE *new_node;
    new_node = malloc(sizeof (NODE_TYPE));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) { // 1つもノードが存在しない場合
        list->head = new_node;
    } else { // 他にnodeがある場合
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

NODE_TYPE *linked_list_find_node(LINKED_LIST *list, int data)
{
    NODE_TYPE *node;

    node = list->head;
    while(node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void linked_list_delete_node(LINKED_LIST *list, NODE_TYPE *node)
{
    if (node == list->head) {
        if (list->head->next == NULL) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        NODE_TYPE *temp;
        temp = list->head;
        while((temp != NULL) && (temp->next != node)) { // nodeが取得できるかつ、引数で受け取ったノードではない
            temp = temp->next;
        }
        if (temp != NULL) {
            temp->next = node->next; // 削除するノードについているnextをセットする。
        }
    }
    free(node);
}

void linked_list_print (LINKED_LIST *list) {
    NODE_TYPE *node;

    printf ("linked list [ ");
    node = list->head;
    while (NULL != node) {
        printf ("%02d ", node->data);
        node = node->next;
    }
    printf ("]\n");
}

int linked_list_count_node (LINKED_LIST * list) {
    NODE_TYPE *node;
    int i;
    i = 0;

    node = list->head;
    while (NULL != node) {
        i++;
        node = node->next;
    }
    return i;
}

int main()
{
    LINKED_LIST *list;
    NODE_TYPE *node;
    int data1, data2, del_data;

    list = malloc(sizeof (LINKED_LIST));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    for (int i = 0; i < DATA_SIZE; ++i) {
        data1 = (int) rand() % 100;
        printf("adding node to head of linked list: ");
        printf("%02d\n", data1);
        linked_list_insert_node_h(list, data1);
    }
    linked_list_print(list);

    for (int i = 0; i < DATA_SIZE; ++i) {
        data2 = (int) rand() % 100;
        printf("adding node to tial of linked list: ");
        printf("%02d\n", data2);
        linked_list_insert_node_t(list, data2);
    }
    linked_list_print(list);

    del_data = data2;
    printf("finding node: [%d]\n", del_data);
    node = linked_list_find_node(list, del_data);
    if (node != NULL) {
        printf("deleting node: [%d]\n", del_data);
        linked_list_delete_node(list, node);
    } else {
        printf("Node not found: [%d]\n", del_data);
    }
    linked_list_print(list);

    printf ("number of node(s): %d\n", linked_list_count_node (list));

    free(list);
    return 0;
}