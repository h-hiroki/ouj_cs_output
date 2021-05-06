#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE_TYPE;

void tree_display(NODE_TYPE *node, int level)
{
    if (node != NULL) {
        tree_display(node->right, level + 1);
        printf("\n");

        for (int i = 0; i < level; ++i) {
            printf("__");
        }
        printf("%d", node->data);
        tree_display(node->left, level + 1);
    }
}

NODE_TYPE *tree_find(NODE_TYPE *node, int data)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->data > data) {
        return tree_find(node->left, data);
    }
    if (node->data < data) {
        return tree_find(node->right, data);
    }

    return node;
}

NODE_TYPE *tree_insert(NODE_TYPE *node, int data)
{
    if (node == NULL) {
        if ((node = malloc(sizeof (NODE_TYPE))) == NULL) {
            printf("\nError: Can not allocate memory");
            exit (-1);
        }

        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else {
        if (node->data > data) {
            node->left = tree_insert(node->left, data);
        }
        if (node->data < data) {
            node->right = tree_insert(node->right, data);
        }
    }

    return node;
}

int main()
{
    NODE_TYPE *root, *node;
    int data[] = { 40, 30, 70, 10, 60, 90, 20, 80 };
    int value;
    root = NULL;

    for (int i = 0; i < 8; ++i) {
        printf("%02d", data[i]);
        root = tree_insert(root, data[i]);
    }
    printf("\n\n*** binary search tree ***");
    tree_display(root, 0);

    value = 80;
    printf("\n\n*** searching for a node [%d]***\n", value);
    node = tree_find(root, value);
    if (node != NULL) {
        printf("node [%d] found!", node->data);
    }
    printf("\n");

    return 0;
}