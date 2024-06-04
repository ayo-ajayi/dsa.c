#include "stack.h"
#include <stdbool.h>

typedef struct Stack
{
    Node *top;
} Stack;

Stack *new_stack(int data)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = new_node(data);
    return stack;
}

void stack_push(Stack *s, int data)
{
    if (stack_is_empty(s))
    {
        printf("error: empty stack");
        return;
    }
    Node *node = new_node(data);
    node->next = s->top;
    s->top = node;
}

int stack_pop(Stack *s, int *data)
{
    if (stack_is_empty(s))
    {
        return 0; // failure
    }
    *data = s->top->data;
    s->top = s->top->next;
    return 1; // success
}

int stack_peek(Stack *s, int *data)
{
    if (stack_is_empty(s))
    {
        return 0; // failure
    }
    *data = s->top->data;
}

bool stack_is_empty(Stack *s)
{
    return s->top == NULL;
}

void free_stack(Stack *stack)
{
    Node *current = stack->top;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}