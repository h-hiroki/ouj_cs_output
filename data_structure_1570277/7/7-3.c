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

NODE_TYPE *tree_find_min(NODE_TYPE *node)
{
    if ((node == NULL) || (node->left == NULL)) {
        return node;
    }
    return tree_find_min(node->left);
}

NODE_TYPE *tree_find_max(NODE_TYPE *node)
{
    if ((node == NULL) || (node->right == NULL)) {
        return node;
    }
    return tree_find_max(node->right);
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

NODE_TYPE *tree_delete(NODE_TYPE *node, int data)
{
    NODE_TYPE *temp;

    if (node == NULL) {
        printf("\nData item not found");
    }
    else if (node->data > data) {
        node->left = tree_delete(node->left, data);
    }
    else if (node->data < data) {
        node->right = tree_delete(node->right, data);
    }
    else {
        if ((node->left) && (node->right)) { // 2つの子がいる場合
            temp = tree_find_min(node->right); // 右側の一番小さい値を取得する
            node->data = temp->data; // 右側の一番小さい値を後任として書き換える
            node->right = tree_delete(node->right, node->data);
        }
        else if (node->left == NULL) {
            temp = node;
            node = node->right;
            free(temp);
        }
        else if (node->right == NULL) {
            temp = node;
            node = node->left;
            free(temp);
        }
    }

    return node;
}

int main()
{
    NODE_TYPE *root;
    int data[] = { 90, 50, 20, 70, 10, 30, 60, 25, 35 };
    int value;
    root = NULL;

    for (int i = 0; i < 9; ++i) {
        printf("%02d ", data[i]);
        root = tree_insert(root, data[i]);
    }

    printf("\n\n*** binary search tree ***");
    tree_display(root, 0);
    printf("\n");

    value = 50;
    printf("\n\n*** delete %d ***", value);
    tree_delete(root, value);

    printf("\n\n*** binary search tree ***");
    tree_display(root, 0);
    printf("\n");

    return 0;
}