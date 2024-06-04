#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

void append_to_tail(Node *node, int data);
void traverse_list(Node *node);
Node *delete_node(Node *node, int data);
void free_linked_list(Node *head);
#endif
