#include <stdio.h>
#define MaxLength 10
typedef int ElementType;

typedef struct
{
  ElementType Elements[MaxLength];//Store the elements
  int Front, Rear;
} Queue;

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
  return ((Q.Rear-Q.Front+1) % MaxLength==0);
}

void EnQueue(ElementType X,Queue *Q)
{
  if(!Full_Queue(*Q))
    {
      if (Empty_Queue(*Q)) Q->Front=0;
      Q->Rear=(Q->Rear+1) % MaxLength;
      Q->Elements[Q->Rear]=X;
    }
  else printf("Queue đầy!");
}

ElementType DeQueue(Queue *Q)
{
  ElementType data;
  data=Q->Elements[Q->Front];
  if (!Empty_Queue(*Q))
    {
    //Nếu queue chỉ chứa một phần tử
    if (Q->Front==Q->Rear)
      MakeNull_Queue(Q);
    else Q->Front=(Q->Front+1) % MaxLength;
    }
  else printf("Queue rỗng!");
  return data;
}

ElementType EnQueueNeuDayThiXoa(ElementType X,Queue *Q)
{
  ElementType data;
  if(!Full_Queue(*Q))
    EnQueue(X,Q);
  else
    {
      data=DeQueue(Q);
      EnQueue(X,Q);
    }
  return data;
}

int main()
{
  Queue Q;
  int i;
  MakeNull_Queue(&Q);
  int a[MaxLength+1];
  printf("Nhap vao day so:");
  for(i=0;i<MaxLength+1;i++)
    {
      scanf("%d",&a[i]);
      if(i<MaxLength) EnQueueNeuDayThiXoa(a[i],&Q);
      else printf("So bi xoa la %d\n",EnQueueNeuDayThiXoa(a[i],&Q));
    }
  
}
