#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
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
  
  printf("%p ",First);
  TempNode = First;
  while(TempNode!=NULL){
   printf("%d:%p ",TempNode->Inf,TempNode->Next);
   TempNode = TempNode->Next;
  }
  printf("\n");
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


// Than chuong trinh chinh
int main(){
    PointerType *ds=NULL,*pv=NULL;
    int i,p;
    // Chen 3 gia tri vao vi tri dau
    ds = InsertToHead(ds,1);ds = InsertToHead(ds,2);ds = InsertToHead(ds,3);
    // In ra danh sach sau khi chen
    printf("In ra danh sach sau khi chen vao dau \n");
    Print(ds);
	
    // Chen so 4 vao vi tri cuoi cua danh sach
    printf("Danh sach sau khi chen 4 vao cuoi \n");
    ds = InsertToLast(ds,4);
    Print(ds);
    
    // In ra danh sach sau khi xoa phan tu dau
    printf("In ra danh sach sau khi xoa dau \n");
    ds = DeleteHead(ds);
    Print(ds);
    
    // In ra danh sach sau khi xoa phan tu cuoi
    printf("In ra danh sach sau khi xoa cuoi \n");
    ds = DeleteLast(ds);
    Print(ds);
    
    // In ra danh sach sau khi xoa phan tu dau
    printf("Cho vi tri ban muon chen 4 vao sau p = ");scanf("%d",&p);
    pv = ds;i=1;
    while(i<p){pv = pv->Next;i++;}
    InsertMiddle(pv,4);
    Print(ds);

    return 0;
}
