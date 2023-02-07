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

typedef struct Student_t
{
  char id[ID_LENGHTH];
  char name[NAME_LENGHTH];
  int grade;

  struct Student_t *Next;
}Student;

typedef HoSoHocSinh ElementType;
typedef Student PointerType;

//Dong Hoa
ElementType DongHoa(PointerType *a,ElementType x)
{
  strcpy(x.name,a->name);
  strcpy(x.id,a->id);
  x.grade=a->grade;
  return x;
}

//Dong Hoa Nguoc
void DongHoaNguoc(ElementType x,PointerType *a)
{
  strcpy(a->name,x.name);
  strcpy(a->id,x.id);
  a->grade=x.grade;

}

PointerType *InsertMiddle(PointerType *Prev, ElementType x)
{
  PointerType *TempNode;
  
  TempNode = (PointerType *)malloc(sizeof(PointerType));
  strcpy(TempNode->id,x.id);
  strcpy(TempNode->name,x.name);
  TempNode->grade=x.grade;
  TempNode->Next = Prev->Next;
  Prev->Next = TempNode;
  
  return TempNode;
}

void Delete(PointerType *Prev){
  ElementType b;
  PointerType *TempNode;
  
  TempNode = Prev->Next; Prev->Next = Prev->Next->Next;
  free(TempNode);
}

PointerType *InsertToHead(PointerType *First, ElementType X){
  PointerType *TempNode;
  
  TempNode = (PointerType *) malloc(sizeof(PointerType));
  strcpy(TempNode->id,X.id);
  strcpy(TempNode->name,X.name);
  TempNode->grade=X.grade;
  
  TempNode->Next = First;
  First = TempNode;
  
  return First;
}

PointerType *InsertToLast(PointerType *First, ElementType X){
  PointerType *NewNode; PointerType *TempNode;

  NewNode = (PointerType *)malloc(sizeof(PointerType));
  strcpy(NewNode->id,X.id);
  strcpy(NewNode->name,X.name);
  NewNode->grade=X.grade;
  NewNode->Next = NULL; 
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
    printf("ID:%s\n",TempNode->id);;
    printf("Ten:%s\n",TempNode->name);
    printf("Diem:%d\n",TempNode->grade);
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

//Dia chi tuong ung

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
  strcpy(TempNode->id,X.id);
  strcpy(TempNode->name,X.name);
  TempNode->grade=X.grade;
  TempNode->Next = Prev->Next;
  Prev->Next = TempNode;
  
  return TempNode;
}

//Xoa phan tu thu n tinh tu 0 tuong ung trong danh sach
void XoaVoiThamSo(PointerType *ds,int n)
{
  ElementType X;
  PointerType *TempNode;
  PointerType *Prev;
  Prev=DiaChiTuongUng(ds,n);
  TempNode = Prev->Next; Prev->Next = Prev->Next->Next;
  //X = TempNode->Inf;
  free(TempNode);
  
}

//Sap xep

void SapXep(PointerType *ds)
{
  ElementType x,y;
  PointerType *pv1,*pv2;
  pv1=ds;
  while(pv1!=NULL)
    {
      pv2=pv1;
      while(pv2!=NULL)
	{
	  if(pv1->grade < pv2->grade)
	  {
	    x=DongHoa(pv1,x);
	    y=DongHoa(pv2,y);
	    DongHoaNguoc(y,pv1);
	    DongHoaNguoc(x,pv2);
	  }
	  pv2=pv2->Next;
      }
      pv1=pv1->Next;
    }
}

// Tim vi tri truoc
  //diem
PointerType *TimViTriTruoc(PointerType *ds, int x)
{
  PointerType *TempNode,*prv=NULL;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      if(TempNode->grade < x)
	break;
      prv=TempNode;
      TempNode=TempNode->Next;
    }
  return prv;
}

//id

PointerType *TimViTriTruocID(PointerType *ds, char *str)
{
  PointerType *TempNode,*prv=NULL;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      if(strcmp(TempNode->id,str)==0)
	break;
      prv=TempNode;
      TempNode=TempNode->Next;
    }
  return prv;
}

 
//Tim vi tri
//diem
PointerType *TimViTriNhiPhanTheoDiem(PointerType *ds,int grade)
{
  int n=SoPhanTu(ds);
  int Lo=0,Hi,Mid;
  Hi=n-1;
  while(Lo<=Hi)
    {
      Mid=(Lo+Hi)/2;
      if(DiaChiTuongUng(ds,Mid)->grade==grade)
	return DiaChiTuongUng(ds,Mid);
      else if(grade<DiaChiTuongUng(ds,Mid)->grade)
	Hi=Mid-1;
      else Lo=Mid+1;
    }
  return NULL;
}
//ten

PointerType *TimViTriNhiPhanTheoTen(PointerType *ds,char *str)
{
  int n=SoPhanTu(ds);
  int Lo=0,Hi,Mid;
  Hi=n-1;
  while(Lo<=Hi)
    {
      Mid=(Lo+Hi)/2;
      if(strcmp(DiaChiTuongUng(ds,Mid)->name,str)==0)
	return DiaChiTuongUng(ds,Mid);
      else if(strcmp(str,DiaChiTuongUng(ds,Mid)->name)<0)
	Hi=Mid-1;
      else Lo=Mid+1;
    }
  return NULL;
}


/*
int binSearch(int List[],int Target,int Size)
{
  int Mid, Lo=0,Hi=Size-1;
  while(Lo<=Hi)
    {
      Mid=(Lo+Hi)/2;
      if(List[Mid]==Target)
	return Mid;
      else if(Target<List[Mid])
	Hi=Mid-1;
      else Lo=Mid+1;
    }
  return -1;
}
*/


int main()
{
  PointerType *ds=NULL,*pv=NULL,*tmp=NULL;
    PointerType a;
    char str[Max];
    ElementType x,y,them;
    int i,p,n;
    int diem;

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


    //Tim hoc sinh qua ten
    printf("Nhap vao ten can tim:");
    __fpurge(stdin);
    gets(str);
    __fpurge(stdin);
    tmp=TimViTriNhiPhanTheoTen(ds,str);
    if(tmp==NULL) printf("Khong tim duoc\n");
    else
      {
	printf("%s\n",tmp->id);
	printf("%s\n",tmp->name);
	printf("%d\n",tmp->grade);
      }
    
    //Tim hoc sinh qua diem
    printf("Nhap vao diem can tim:");
    scanf("%d",&diem);
    tmp=TimViTriNhiPhanTheoDiem(ds,diem);
    if(tmp==NULL) printf("Khong tim duoc\n");
    else
      {
	printf("%s\n",tmp->id);
	printf("%s\n",tmp->name);
	printf("%d\n",tmp->grade);
      }
}
