#include <stdio.h>
#include <stdlib.h>
#include "hangDoiDanhSach.h"

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
  return (Q.Front==NULL);
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
