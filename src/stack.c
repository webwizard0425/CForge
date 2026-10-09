
#include "cforge/stack.h"

#include <stdlib.h>
#include <string.h>

void init(Stack *stack, size_t element_size)
{
    stack->data = malloc(SIZE * element_size);
    stack->top = 0;
    stack->element_size = element_size;
}

bool isFull(Stack *stack)
{
    return stack->top == SIZE;
}

bool isEmpty(Stack *stack)
{
    return stack->top == 0;
}

void push(Stack *stack, const void *item)
{
    if (isFull(stack) || item == NULL)
        return;

    memcpy(
        (char *)stack->data + stack->top * stack->element_size,
        item,
        stack->element_size
    );

    stack->top++;
}

bool pop(Stack *stack, void *out)
{
    if (isEmpty(stack) || out == NULL)
        return false;

    stack->top--;

    memcpy(
        out,
        (char *)stack->data + stack->top * stack->element_size,
        stack->element_size
    );

    return true;
}

bool peek(Stack *stack, void *out)
{
    if (isEmpty(stack) || out == NULL)
        return false;

    memcpy(
        out,
        (char *)stack->data + (stack->top - 1) * stack->element_size,
        stack->element_size
    );

    return true;
}