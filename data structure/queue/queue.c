#include <stdio.h>
#define QUEUE_SIZE 5

// typedef struct
// {

//     int head, tail;
//     int data[QUEUE_SIZE + 1];

// } Queue;

// void Enqueue(Queue *q, int item)
// {

//     if ((q->tail + 1) % (QUEUE_SIZE + 1) == q->head)
//     {
//         printf("Queue is Full!!\n");
//         return;
//     }

//     q->data[q->tail] = item;
//     q->tail = (q->tail + 1) % (QUEUE_SIZE + 1);
// }

// int Dequeue(Queue *q)
// {
//     if (q->head == q->tail)
//     {
//         printf("Queue is Empty!!\n");
//         return -1;
//     }
//     else
//     {

//         int item = q->data[q->head];
//         q->data[q->head] = -1;
//         q->head = (q->head + 1) % (QUEUE_SIZE + 1);
//         return item;
//     }
// }

typedef struct
{
    int data[QUEUE_SIZE + 1];
    int head, tail;
} Queue;

void Enqueue(Queue *q, int item)
{

    if ((q->tail + 1) % (QUEUE_SIZE + 1) == q->head)
    {
        printf("Queue is full!\n");
        return;
    }

    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (QUEUE_SIZE + 1);
}

int Dequeue(Queue *q)
{

    if (q->head == q->tail)
    {
        printf("Queue is empty!!\n");
        return -1;
    }

    int item = q->data[q->head];
    q->head = (q->head + 1) % (QUEUE_SIZE + 1);
    return item;
}

int main()
{
    int i = 0;
    Queue new_Queue;
    new_Queue.head = 0;
    new_Queue.tail = 0;

    Enqueue(&new_Queue, 10);
    Enqueue(&new_Queue, 20);
    Enqueue(&new_Queue, 30);
    Enqueue(&new_Queue, 40);
    Enqueue(&new_Queue, 50);
    Enqueue(&new_Queue, 60);

    Dequeue(&new_Queue);
    Enqueue(&new_Queue, 50);
    Enqueue(&new_Queue, 50);

    printf("head:%d  tail:%d\n", new_Queue.head, new_Queue.tail);

    return 0;
}