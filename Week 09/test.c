#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#define Max 100
#define MaxDanhBa 100
#define SoLuong 10
#define MaxLength 100


typedef struct DanhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;


typedef int elmType;

typedef struct nodeType
{
  elmType element;
  struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

void MakeNullTree (treetype *T)
{
  (*T)=NULL;
}

void InsertNode( elmType x, treetype *Root)
{
  if(*Root==NULL)
    {
      *Root=(node_Type*)malloc(sizeof(node_Type));
      (*Root)->element=x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if(x<(*Root)->element) InsertNode(x,&(*Root)->left);
  else if(x>(*Root)->element) InsertNode(x,&(*Root)->right);
}


typedef treetype ElementType;
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
  else printf("Queue đã đầy!");
}

ElementType DeQueue(Queue *Q)
{
  treetype data;
  data=Q->Elements[Q->Front];
  if(!Empty_Queue(*Q))
    {
      Q->Front=Q->Front+1;
      if (Q->Front > Q->Rear)
	MakeNull_Queue(Q);// Queue trở thành rỗng
    }
  else printf("Queue bị rỗng!");
  return data;
}

/*
ElementType dequeue(Queue *Q)
{
  if(Empty_Queue(*Q))
    return 0;
  treetype data = Q->Front;
  Q->front = Q->front + 1;
  return data;
}
*/
void breadth_first(treetype node)
{
  Queue queue; // queue of pointers

  MakeNull_Queue(&queue);
  if(node!=NULL)
    {
      //printf(".\n");
      EnQueue(node,&queue);
      while (!Empty_Queue(queue))
	{
	  //printf(",\n");
	  node=DeQueue(&queue);
	  printf("%d\n",node->element);
		 //printf("So dien thoai:%s\n",(node->element).tel);
		 //printf("Email:%s\n\n",(node->element).mail);	  
	  if (node->left !=NULL)
	    EnQueue(node->left,&queue);
	  if (node->right !=NULL)
	    EnQueue(node->right,&queue);
	}
    }
}

int main()
{

  elmType danhBa;
  int i,j,n,m;
  char str[Max],mail[Max];
  treetype T;
  treetype mkr;
  MakeNullTree(&T);
  FILE *fptr;
  
  fptr=fopen("danhBa.txt","r");
  // printf("Cac email:\n\n");
  for(i=0;i<SoLuong;i++)
    {
      if(i%4==0) j=i+10;
      else j=i;
      InsertNode(j,&T);
    }
  breadth_first(T);
}
