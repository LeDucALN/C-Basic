#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define Max 30
#define B 15 // kích thước của bảng băm
#define z 22

typedef struct DanhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;

typedef address KeyType; // int
typedef char *ElementType;

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


int intergerCast(ElementType s)
{
  int i,n;
  int key;
  key=0;
  n=strlen(s);
  for(i=0;i<n;i++)
    key=key+s[i];
  key=key%B;
  return key;
}
/*
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
*/

int Search(ElementType X)
{
  Position P;
  int Found=0;
  P=D[intergerCast(X)]; //Tới bucket H(X)
  //Duyệt danh sách tại bucket H(X)
  while((P!=NULL) && (!Found))
    if (strcmp((P->Key).mail,X)==0) Found=1;
    else P=P->Next;
  return Found;
}

void InsertSet(KeyType X)
{
  int Bucket;
  Position P;
  if (!Search(X.mail))
    {
      Bucket=intergerCast(X.mail);
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
  Bucket=intergerCast(X);
// Nếu danh sách đã tồn tại
  if (D[Bucket]!=NULL)
    {
// Nếu X ở đầu danh sách
      if(strcmp((D[Bucket]->Key).mail,X)==0)
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
	    if (strcmp((P->Next->Key).mail,X)==0)
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
  for (b = 0;b<B;b++)
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

void traversebucket(int b)
{
  Position p;
  p= D[b];
  while (p !=NULL)
    {
      // Giả sử key có kiểu int
      printf("Ten:%s",p->Key.name);
      printf("So Dien Thoai:%s",p->Key.tel);
      printf("Mail:%s\n",p->Key.mail);
    
      p= p->Next;
    }
}

void traverse()
{
  int b;
  for (b=0;b<B;b++)
    {
      printf("\nBucket %d:\n",b+1);
      traversebucket(b);
    }
}
int main()
{
  int i;
  char str[Max];
  address danhBa;
  FILE *fptr;
  MakeNullSet();
  fptr=fopen("danhBa.txt","r");
  while(!feof(fptr))
    {
      fgets(str,100,fptr);
      fgets(danhBa.name,100,fptr);
      // danhBa.name[strlen(danhBa.name)-1]='\0';
      //printf("\n%s\n",danhBa[i].name);
      fgets(danhBa.tel,100,fptr);
      // danhBa.tel[strlen(danhBa.tel)-1]='\0';
      fgets(danhBa.mail,100,fptr);
      //danhBa.mail[strlen(danhBa.mail)-1]='\0';
      InsertSet(danhBa); 
    }
  traverse();
  fclose(fptr);
}
