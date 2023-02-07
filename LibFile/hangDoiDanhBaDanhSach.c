#include <stdlib.h>
#include "queue.h"

void initialize(Queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(Queue *q)
{
    return (q->rear == NULL);
}

void enQueue(Queue *q, ElementType value)
{
    if (q->count < FULL)
    {
        Node *tmp;
        tmp = malloc(sizeof(Node));
        tmp->data = value;
        tmp->next = NULL;
        if (!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("List is full\n");
    }
}

ElementType deQueue(Queue *q)
{
    Node *tmp;
    ElementType n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return (n);
}

// void display(Node *head)
// {
//     if (head == NULL)
//     {
//         printf("NULL\n");
//     }
//     else
//     {
//         printf("%d\n", head->data);
//         display(head->next);
//     }
// }

