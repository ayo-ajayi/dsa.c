#ifndef TREE_H
#define TREE_H

typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTreeNode *new_binary_tree(int data);
void tree_insert(BinaryTreeNode *tree, int data);
void inorder_traversal(BinaryTreeNode *tree);
void free_tree(BinaryTreeNode *tree);

#endif