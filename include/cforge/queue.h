
#ifndef CFORGE_QUEUE_H
#define CFORGE_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

#define SIZE 10000

typedef struct {
    void *data;
    size_t front;
    size_t rear;
    size_t element_size;
} Queue;

void init(Queue *queue, size_t element_size);

bool is_Full(Queue *queue);

bool is_Empty(Queue *queue);

size_t size(Queue *queue);

void push(Queue *queue, const void *item);

bool poll(Queue *queue, void *out);

bool top(Queue *queue, void *out);

#endif