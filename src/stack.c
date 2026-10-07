#include "cforge/stack.h"

void init(Stack *stack)
{
    stack->top = -1;
}

bool isFull(Stack *stack)
{
    return stack->top == SIZE - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;

    stack->data[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;

    return stack->data[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
        return -1;

    return stack->data[stack->top];
}