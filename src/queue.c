
#include "cforge/queue.h"

#include <stdlib.h>
#include <string.h>

void init(Queue *queue, size_t element_size)
{
    queue->data = malloc(SIZE * element_size);
    queue->front = 0;
    queue->rear = 0;
    queue->element_size = element_size;
}

bool is_Full(Queue *queue)
{
    return queue->rear == SIZE;
}

bool is_Empty(Queue *queue)
{
    return queue->front == queue->rear;
}

size_t size(Queue *queue)
{
    return queue->rear - queue->front;
}

void push(Queue *queue, const void *item)
{
    if (is_Full(queue) || item == NULL)
        return;

    memcpy(
        (char *)queue->data + queue->rear * queue->element_size,
        item,
        queue->element_size
    );

    queue->rear++;
}

bool poll(Queue *queue, void *out)
{
    if (is_Empty(queue) || out == NULL)
        return false;

    memcpy(
        out,
        (char *)queue->data + queue->front * queue->element_size,
        queue->element_size
    );

    queue->front++;

    return true;
}

bool top(Queue *queue, void *out)
{
    if (is_Empty(queue) || out == NULL)
        return false;

    memcpy(
        out,
        (char *)queue->data + queue->front * queue->element_size,
        queue->element_size
    );

    return true;
}