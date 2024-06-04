#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <stdbool.h>

typedef struct Stack Stack;

Stack *new_stack(int data);
void stack_push(Stack *s, int data);
int stack_pop(Stack *s, int *data);
int stack_peek(Stack *s, int *data);
bool stack_is_empty(Stack *s);
void free_stack(Stack *stack);

#endif