
#ifndef CFORGE_STACK_H
#define CFORGE_STACK_H

#include <stdbool.h>
#include <stddef.h>

#define SIZE 10000

typedef struct {
    void *data;
    size_t top;
    size_t element_size;
} Stack;

void init(Stack *stack, size_t element_size);

bool isFull(Stack *stack);

bool isEmpty(Stack *stack);

void push(Stack *stack, const void *item);

bool pop(Stack *stack, void *out);

bool peek(Stack *stack, void *out);

#endif