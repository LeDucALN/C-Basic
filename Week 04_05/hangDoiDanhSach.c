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

void MakeNullQueue(Queue *Q)
{
  Position Header;
  Header=(Node*)malloc(sizeof(Node));
  // Allocation Header
  Header->Next=NULL;
  Q->Front=Header;
  Q->Rear=Header;
}

int EmptyQueue(Queue Q)
{
  return (Q.Front==Q.Rear);
}

void EnQueue(ElementType X, Queue *Q)
{
  Q->Rear->Next=(Node*)malloc(sizeof(Node));
  Q->Rear=Q->Rear->Next;
  Q->Rear->Element=X;
  Q->Rear->Next=NULL;
}

ElementType DeQueue(Queue *Q)
{
  ElementType data;
  data=Q->Front->Element;
  if(!EmptyQueue(*Q))
    {
      Position T;
      T=Q->Front;
      Q->Front=Q->Front->Next;
      free(T);
    }
  else printf("Queue is empty.\n");
  return data;
}

int main()
{}
