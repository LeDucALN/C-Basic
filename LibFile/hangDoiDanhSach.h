#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node
{
  ElementType Element;
  struct Node* Next; //pointer to next element
}Node;

typedef Node* Position;

typedef struct
{
  Position Front, Rear;
}Queue;

void MakeNullQueue(Queue *Q);
int EmptyQueue(Queue Q);
void EnQueue(ElementType X, Queue *Q);
ElementType DeQueue(Queue *Q);
