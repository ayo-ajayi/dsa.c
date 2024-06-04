#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "tree.h"

int main()
{
    Node *linked_list = new_node(2);
    int arr[] = {5, 7, 8, 5};
    for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
        append_to_tail(linked_list, arr[i]);
    traverse_list(linked_list);
    printf("\n");
    linked_list = delete_node(linked_list, 5);
    traverse_list(linked_list);
    printf("\n");
    free_linked_list(linked_list);

    Stack *stack = new_stack(7);
    int arr_stack[] = {2, 7, 5, 3, 5};
    for (size_t i = 0; i < sizeof(arr_stack) / sizeof(int); i++)
        stack_push(stack, arr_stack[i]);

    int pop;
    if (!stack_pop(stack, &pop))
    {
        printf("error: stack is empty\n");
    }
    printf("the value that just poped is: %d\n", pop);

    int peek;
    if (!stack_peek(stack, &peek))
    {
        printf("error: stack is empty\n");
    }
    printf("the top value in stack is: %d\n", peek);
    free_stack(stack);

    BinaryTreeNode *tree = new_binary_tree(2);
    tree_insert(tree, 3);
    tree_insert(tree, 7);
    tree_insert(tree, 5);
    inorder_traversal(tree);
    free_tree(tree);

    return 0;
}