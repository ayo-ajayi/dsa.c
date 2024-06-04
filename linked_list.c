#include "linked_list.h"

void append_to_tail(Node *node, int data)
{
    Node *n = new_node(data);
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = n;
}

void traverse_list(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

Node *delete_node(Node *node, int data)
{
    Node *head = node;
    if (node->data == data)
    {
        return head->next;
    }
    while (node != NULL)
    {
        if (data == node->next->data)
        {
            node->next = node->next->next;
        }
        node = node->next;
    }
    free(node);
    return head;
}

void free_linked_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}