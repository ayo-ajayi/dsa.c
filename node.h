#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *new_node(int data);

#endif