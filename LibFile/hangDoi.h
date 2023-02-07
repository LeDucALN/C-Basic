#include <stdio.h>
#define MaxLength 100
typedef int ElementType;

typedef struct
{
  ElementType Elements[MaxLength];//Store the elements
  int Front, Rear;
} Queue;

void MakeNull_Queue(Queue *Q);
int Empty_Queue(Queue Q);
int Full_Queue(Queue Q);
void EnQueue(ElementType X,Queue *Q);
ElementType DeQueue(Queue *Q);
