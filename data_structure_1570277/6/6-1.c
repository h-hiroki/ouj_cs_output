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
            printf("_");
        }
        printf("%d", node->data);
        tree_display(node->left, level + 1);
    }
}

int main()
{
    NODE_TYPE *root;

    root = malloc(sizeof (NODE_TYPE));
    root->data = 40;

    root->left = malloc(sizeof (NODE_TYPE));
    root->left->data = 30;

    root->right = malloc(sizeof (NODE_TYPE));
    root->right->data = 70;

    root->left->left = malloc(sizeof (NODE_TYPE));
    root->left->left->data = 10;
    root->left->right = NULL;

    root->right->left = malloc(sizeof (NODE_TYPE));
    root->right->left->data = 60;
    root->right->left = NULL;
    root->right->right = NULL;

    root->right->right = malloc(sizeof (NODE_TYPE));
    root->right->right->data = 90;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    root->left->left->right = malloc(sizeof (NODE_TYPE));
    root->left->left->right->data = 20;
    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;

    tree_display(root, 0);
    printf("\n");

    return 0;
}