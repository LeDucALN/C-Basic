#include <stdio.h>
#include "hangDoi.h"

void MakeNull_Queue(Queue *Q)
{
  Q->Front=-1;
  Q->Rear=-1;
}

int Empty_Queue(Queue Q)
{
  return Q.Front==-1;
}

int Full_Queue(Queue Q)
{
  return (Q.Rear-Q.Front+1)==MaxLength;
}

void EnQueue(ElementType X,Queue *Q)
{
  if(!Full_Queue(*Q))
    {
      if (Empty_Queue(*Q))
	Q->Front=0;
      Q->Rear=Q->Rear+1;
      Q->Elements[Q->Rear]=X;
    }
  else printf("Queue is full\n");
}

ElementType DeQueue(Queue *Q)
{
  ElementType data;
  data=Q->Elements[Q->Front];
  if(!Empty_Queue(*Q))
    {
      Q->Front=Q->Front+1;
      if (Q->Front > Q->Rear)
	MakeNull_Queue(Q);// Queue trở thành rỗng
    }
  else printf("Queue is empty!\n");
  return data;
}
