#include "cforge/queue.h"

void init(Queue *queue)
{
    queue->front = 0;
    queue->rear = -1;
}

bool is_Full(Queue *queue)
{
    return queue->rear == SIZE - 1;
}

bool is_Empty(Queue *queue)
{
    return queue->front > queue->rear;
}
int size(Queue *queue)
{
    if (is_Empty(queue))
        return 0;

    return queue->rear - queue->front + 1;
}

void push(Queue *queue, int item)
{
    if (is_Full(queue))
        return;

    queue->data[++queue->rear] = item;
}

int poll(Queue *queue)
{
    if (is_Empty(queue))
        return -1;

    return queue->data[queue->front++];
}

int top(Queue *queue)
{
    if (is_Empty(queue))
        return -1;

    return queue->data[queue->front];
}