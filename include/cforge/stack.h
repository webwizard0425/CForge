#ifndef CFORGE_STACK_H
#define CFORGE_STACK_H

#include <stdbool.h>

#define SIZE 10000

typedef struct
{
    int data[SIZE];
    int top;
} Stack;

void init(Stack *stack);

bool isFull(Stack *stack);
bool isEmpty(Stack *stack);

void push(Stack *stack, int item);

int pop(Stack *stack);
int peek(Stack *stack);

#endif