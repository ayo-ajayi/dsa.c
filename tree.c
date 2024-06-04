#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
} BinaryTreeNode;

BinaryTreeNode *new_binary_tree(int data)
{
    BinaryTreeNode *b = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (b == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    b->data = data;
    b->left = NULL;
    b->right = NULL;
    return b;
}

void tree_insert(BinaryTreeNode *tree, int data)
{
    if (tree == NULL)
        return;

    if (data < tree->data)
    {
        if (tree->left != NULL)
        {
            tree_insert(tree->left, data);
            return;
        }
        tree->left = new_binary_tree(data);
    }
    else
    {
        if (tree->right != NULL)
        {
            tree_insert(tree->right, data);
            return;
        }
        tree->right = new_binary_tree(data);
    }
}

void inorder_traversal(BinaryTreeNode *tree)
{
    if (tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("visiting: %d\n", tree->data);
        inorder_traversal(tree->right);
    }
}

void free_tree(BinaryTreeNode *tree)
{
    if (tree == NULL)
        return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}