#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define Max 50
#define ID_LENGHTH 15
#define NAME_LENGHTH 50

typedef struct HoSo
{
  char id[ID_LENGHTH];
  char name[NAME_LENGHTH];
  int grade;
}HoSoHocSinh;

typedef HoSoHocSinh ElementType;

typedef struct Student_t
{
  ElementType Inf;
  struct Student_t *Next;
}Student;

typedef Student PointerType;


PointerType *InsertToHead(PointerType *First, ElementType X){
  PointerType *TempNode;
  
  TempNode = (PointerType *) malloc(sizeof(PointerType));
  strcpy((TempNode->Inf).id,X.id);
  strcpy((TempNode->Inf).name,X.name);
  (TempNode->Inf).grade=X.grade;
  
  TempNode->Next = First;
  First = TempNode;
  
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
    printf("ID:%s\n",(TempNode->Inf).id);;
    printf("Ten:%s\n",(TempNode->Inf).name);
    printf("Diem:%d\n",(TempNode->Inf).grade);
    printf("\n");
    i++;
   TempNode = TempNode->Next;
  }
  printf("\n");
}

PointerType *TimViTri(PointerType *ds, char *str)
{
  PointerType *TempNode;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      if(strcmp((TempNode->Inf).id,str)==0)
	{
	  return TempNode;
	}
      TempNode=TempNode->Next;
    }
  return TempNode;
}

void SapXep(PointerType *ds)
{
  ElementType Temp;
  PointerType *pv1,*pv2;
  pv1=ds;
  while(pv1!=NULL)
    {
      pv2=pv1;
      while(pv2!=NULL)
	{
	  if((pv1->Inf).grade < (pv2->Inf).grade)
	  {
	    Temp=pv1->Inf;
	    pv1->Inf=pv2->Inf;
	    pv2->Inf=Temp;
	  }
	  pv2=pv2->Next;
      }
      pv1=pv1->Next;
    }
}

void DoiDiem(PointerType *ds, char *str, int diemMoi)
{
  PointerType *n;
  n=TimViTri(ds,str);
  if(n==NULL) printf("Khong co ID nay\n");
  else
    {
      (n->Inf).grade=diemMoi;
    }
}


int main()
{
  PointerType *ds=NULL,*pv=NULL,*tmp=NULL;
    PointerType a;
    char str[Max];
    ElementType x,y,them;
    int i,p,n;
    int diemMoi;

    //Nhap so luong tuy y
    while(1)
      {
	__fpurge(stdin);
	printf("Nhap vao ID:");
	gets(x.id);
	__fpurge(stdin);
	printf("Nhap vao ten:");
	gets(x.name);
	__fpurge(stdin);
	printf("Nhap vao diem:");
	scanf("%d",&x.grade);
	__fpurge(stdin);
	
	ds=InsertToHead(ds,x);

	printf("Nhap 0 neu muon dung lai\n Nhap so khac neu chua\n");
	scanf("%d",&i);
	if(i==0) break;
      }
    printf("\n");
    SapXep(ds);
    Print(ds);
        //Tim hoc sinh qua ID
    /*
    printf("Nhap vao ID can tim:");
    __fpurge(stdin);
    gets(str);
    tmp=TimViTri(ds,str);
    if(tmp==NULL) printf("Khong tim duoc\n");
    else
      {
	printf("%s\n",(tmp->Inf).id);
	printf("%s\n",(tmp->Inf).name);
	printf("%d\n",(tmp->Inf).grade);
      }
    */
    
    //Doi Diem

    printf("Nhap vao ID cua nguoi ban muon doi diem:");
    __fpurge(stdin);
    gets(str);
    tmp=TimViTri(ds,str);
    if(tmp==NULL) printf("Khong tim duoc\n");
    else
      {
	printf("Nhap vao diem moi:");
	scanf("%d",&diemMoi);
	DoiDiem(ds,str,diemMoi);
      }
    printf("Danh sach moi:\n");
    SapXep(ds);
    Print(ds);
    
}
