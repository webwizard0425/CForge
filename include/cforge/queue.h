#ifndef CFORGE_QUEUE_H
#define CFORGE_QUEUE_H

#include <stdbool.h>

#define SIZE 10000

typedef struct
{
    int data[SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *queue);
int size(Queue *queue);
bool is_Full(Queue *queue);
bool is_Empty(Queue *queue);

void push(Queue *queue, int item);

int poll(Queue *queue);
int top(Queue *queue);

#endif