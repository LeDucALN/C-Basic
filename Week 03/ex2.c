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

//In
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

//Tim So Phan Tu
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

//Chen voi phan tu thu n tinh tu 0 tuong ung trong danh sach
PointerType *ChenVoiThamSo(PointerType *ds,int n, ElementType X)
{
  PointerType *TempNode;
  PointerType *Prev;
  Prev=DiaChiTuongUng(ds,n);
  TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = Prev->Next;
  Prev->Next = TempNode;
  
  return TempNode;
}

//Xoa phan tu thu n tinh tu 0 tuong ung trong danh sach
ElementType XoaVoiThamSo(PointerType *ds,int n)
{
  ElementType X;
  PointerType *TempNode;
  PointerType *Prev;
  Prev=DiaChiTuongUng(ds,n);
  TempNode = Prev->Next; Prev->Next = Prev->Next->Next;
  X = TempNode->Inf;
  free(TempNode);
  
  return X;
}


int main()
{
    PointerType *ds=NULL,*pv=NULL;
    address x,y;
    int i,p,n;

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
    printf("\n");
    Print(ds);

    printf("Ban muon xoa phan tu thu:");
    scanf("%d",&i);
    n=SoPhanTu(ds);
    if(i==1) DeleteHead(ds);
    else if(i==n) DeleteLast(ds);
    else
      XoaVoiThamSo(ds,i-1);
    Print(ds);
    
    printf("Ban muon chen vao sau phan tu thu may:");
    scanf("%d",&i);
    __fpurge(stdin);
    printf("Nhap vao ten:");
    gets(y.name);
    __fpurge(stdin);
    printf("Nhap vao so dien thoai:");
    gets(y.tel);
    __fpurge(stdin);
    printf("Nhap vao mail:");
    gets(y.mail);
    __fpurge(stdin);
    if(i==0) InsertToHead(ds,y);
    if(i==n) InsertToLast(ds,y);
    else
      ChenVoiThamSo(ds,i-1,y);
    Print(ds);
}
