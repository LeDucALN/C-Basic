#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define B 15 // kích thước của bảng băm
#define z 22

typedef int KeyType; // int
typedef int ElementType;

typedef struct Node
{
  KeyType Key;
// Thêm các trường mới nếu cần
  struct Node* Next;
}Node;
typedef Node* Position;
typedef Position Dictionary[B];
Dictionary D;

void MakeNullSet()
{
  int i;
  for(i=0;i<B;i++)
    D[i]=NULL;
}


int intergerCast(char s[])
{
  int i,n;
  int key;
  key=0;
  n=strlen(s);
  for(i=0;i<n;i++)
    key=key+s[i];
  return key;
}

long daThuc(char s[])
{
  int i,n;
  long key;
  key=0;
  n=strlen(s);
  for(i=0;i<n;i++)
    key=key+pow(z,i)*s[i];
  return key;
}

int tongCacThanhPhan(long i)
{
  return (int) ((i>>32)+(int)i);
}

int Search(KeyType X)
{
  Position P;
  int Found=0;
  P=D[H(X)]; //Tới bucket H(X)
  //Duyệt danh sách tại bucket H(X)
  while((P!=NULL) && (!Found))
    if (P->Key==X) Found=1;
    else P=P->Next;
  return Found;
}

void InsertSet(KeyType X)
{
  int Bucket;
  Position P;
  if (!Search(X))
    {
      Bucket=H(X);
      P=D[Bucket];
      //them một node mới tại D[Bucket
      D[Bucket] = (Node*)malloc(sizeof(Node));
      D[Bucket] ->Key=X;
      D[Bucket] ->Next=P;
    }
}

void DeleteSet(ElementType X)
{
  int Bucket, Done;
  Position P,Q;
  Bucket=H(X);
// Nếu danh sách đã tồn tại
  if (D[Bucket]!=NULL)
    {
// Nếu X ở đầu danh sách
      if(D[Bucket]->Key==X)
	{
	  Q=D[Bucket];
	  D[Bucket]=D[Bucket]->Next;
	  free(Q);
	}

      else
	{
	  // Tìm X
	  Done=0;
	  P=D[Bucket];
	  while ((P->Next!=NULL) &&(!Done))
	    if (P->Next->Key==X)
	      Done=1;
	    else P=P->Next;
	  if (Done)
	    {
	      // Nếu thấy
	      // Delete P->Next
	      Q=P->Next;
	      P->Next=Q->Next;
	      free(Q);
	    }
	}
    }
}

int emptybucket (int b)
{
  return(D[b] ==NULL ? 1:0);
}

int empty( )
{
  int b;
  for (b = 0; b<B;b++)
    if(D[b] !=NULL)
       return 0;
return 1;
}

void clearbucket (int b)
{
  Position p,q;
  q = NULL;
  p = D[b];
  while(p !=NULL)
    {
      q = p;
      p=p->Next;
      free (q);
    }
  D[b] = NULL;
}

void clear( )
{
  int b;
  for (b = 0; b<B ; b++)
    clearbucket(b);
}

void traversebucket (int b)
{
  Position p;
  p= D[b];
  while (p !=NULL)
    {
      // Giả sử key có kiểu int
      printf("%3d\n", p->Key);
      p= p->Next;
    }
}

void traverse()
{
  int b;
  for (b = 0;b<B; b++)
    {
      printf("\nBucket %d:",b);
      traversebucket(b);
    }
}
int main()
{}
