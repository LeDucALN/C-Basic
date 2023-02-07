#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define Max 50

typedef struct danhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;

typedef address ElementType;
struct _PointerType{
  ElementType Inf;
  struct _PointerType *Next;
};

typedef struct _PointerType PointerType;

PointerType *InsertMiddle(PointerType *Prev, ElementType X)
{
  PointerType *TempNode;
  
  TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = Prev->Next;
  Prev->Next = TempNode;
  
  return TempNode;
}

ElementType Delete(PointerType *Prev){
  ElementType X;
  PointerType *TempNode;
  
  TempNode = Prev->Next; Prev->Next = Prev->Next->Next;
  X = TempNode->Inf;
  free(TempNode);
  
  return X;
}

PointerType *InsertToHead(PointerType *First, ElementType X){
  PointerType *TempNode;
  
  TempNode = (PointerType *) malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = First;
  First = TempNode;
  
  return First;
}

PointerType *InsertToLast(PointerType *First, ElementType X){
  PointerType *NewNode; PointerType *TempNode;

  NewNode = (PointerType *)malloc(sizeof(PointerType));
  NewNode->Inf = X;NewNode->Next = NULL; 
  TempNode = First;
  
  while(TempNode->Next!=NULL)
    TempNode = TempNode->Next;
  
  TempNode->Next = NewNode;
  return First;
}

PointerType *DeleteHead(PointerType *First){
  PointerType *TempNode;
  
  TempNode = First->Next;
  free(First);
  
  return TempNode;
}

PointerType *DeleteLast(PointerType *First){
  PointerType *Temp1,*Temp2;
  Temp1 = First; Temp2 = First;
  
  while(Temp1->Next != NULL){
   Temp2 = Temp1;
   Temp1 = Temp1->Next;}
  
  Temp2->Next = NULL;
  free(Temp1);
  return First;
}

int IsEmpty(PointerType *First)
{
  return !First;
}

PointerType *MakeNull(PointerType *First)
{
  while(!IsEmpty(First))
   First=DeleteHead(First);
  return First;
}

void Print(PointerType *First){
  PointerType *TempNode;
  int i;
  i=1;
  
  // printf("%p ",First);
  TempNode = First;
  while(TempNode!=NULL){
    printf("%d\n",i);
    printf("%s\n",(TempNode->Inf).name);
    printf("%s\n",(TempNode->Inf).tel);
    printf("%s\n",(TempNode->Inf).mail);
    printf("\n");
    i++;
   TempNode = TempNode->Next;
  }
  printf("\n");
}

int SoPhanTu(PointerType *First)
{
  PointerType *pt1;
  int count;
  count=1;
  pt1=First;
  while(pt1->Next!=NULL)
    {
      pt1=pt1->Next;
      count++;
    }
  return count;
}

PointerType *DiaChiTuongUng(PointerType *ds,int n)
{
  PointerType *pt1;
  int i;
  pt1=ds;
  for(i=0;i<n;i++)
    pt1=pt1->Next;
  return pt1;
}
int main()
{
    PointerType *ds=NULL,*pv=NULL;
    address x;
    int i,p;

    //Nhap so luong tuy y
    while(1)
      {
	__fpurge(stdin);
	printf("Nhap vao ten:");
	gets(x.name);
	__fpurge(stdin);
	printf("Nhap vao so dien thoai:");
	gets(x.tel);
	__fpurge(stdin);
	printf("Nhap vao mail:");
	gets(x.mail);
	__fpurge(stdin);
	
	ds=InsertToHead(ds,x);

	printf("Nhap 0 neu muon dung lai\n Nhap so khac neu chua\n");
	scanf("%d",&i);
	if(i==0) break;
      }

    //Chen 1 phan tu ao phan tu hien thoi
	__fpurge(stdin);
	printf("Nhap vao ten can chen:");
	gets(x.name);
	__fpurge(stdin);
	printf("Nhap vao so dien thoai can chen:");
	gets(x.tel);
	__fpurge(stdin);
	printf("Nhap vao mail can chen:");
	gets(x.mail);
	__fpurge(stdin);
	
	InsertMiddle(ds,x);

	//Duyet va in
	Print(ds);

	//xoa node
	printf("Ban muon xoa phan tu thu may:");
	scanf("%d",&i);
	i=i-1;
	if(i==0) DeleteHead(ds);
	else if(i==SoPhanTu(ds)-1) DeleteLast(ds);
	else
	  {
	    Delete(DiaChiTuongUng(ds,i-1));
	  }
	Print(ds);
    
}
