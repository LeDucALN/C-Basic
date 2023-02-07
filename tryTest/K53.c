#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define Max 100

typedef struct
{
  int maSP;
  char ten[Max];
  int gia;
  int soluong;
}SanPham;
typedef SanPham ElementType;
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
  
  //printf("%p ",First);
  TempNode = First;
  while(TempNode!=NULL){
    //printf("%d:%p ",TempNode->Inf,TempNode->Next);
    printf(" %-5d%-10d%-5d%-10s\n",TempNode->Inf.maSP,TempNode->Inf.gia,TempNode->Inf.soluong,TempNode->Inf.ten);
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

int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Nhap san pham");
  printf("|%5d|%-50s|\n",2,"Doc tep");
  printf("|%5d|%-50s|\n",3,"Sap xep");
  printf("|%5d|%-50s|\n",4,"Tinh tong tien");
  printf("|%5d|%-50s|\n",5,"Dem nhom san pham trung gia");
  printf("|%5d|%-50s|\n",6,"Dem nhom san pham trung ten");
  printf("|%5d|%-50s|\n",7,"Thoat");
  printf("+-----+--------------------------------------------------+\n");

  do
    {
      __fpurge(stdin);
      printf("Nhap vao lua chon cua ban:");
      buff=scanf("%d%c",&luaChon,&c);
      if(buff!=2&&c!='\n'||luaChon<a||luaChon>b) printf("Ban da nhap sai cu phap\n");
    }while(buff!=2&&c!='\n'||luaChon<a||luaChon>b);
  return luaChon;
}

//2, nhap so Nguyen
int checkMa(int a, char cc[])
{
  int so,buff;
  char c;
  do
    {
      __fpurge(stdin);
      printf("Nhap vao %s:",cc);
      buff=scanf("%d%c",&so,&c);
      if(so==0) return 0;
      if(buff!=2||c!='\n'||so<=a) printf("Ban da nhap sai cu phap\n");
    }while(buff!=2||c!='\n'||so<=a);
  return so;
}

int checkSoNguyenKhongAm(char cc[])
{
  int so,buff;
  char c;
  do
    {
      __fpurge(stdin);
      printf("%s:",cc);
      buff=scanf("%d%c",&so,&c);
      if(buff!=2||c!='\n'||so<=0) printf("Ban da nhap sai cu phap\n");
    }while(buff!=2||c!='\n'||so<=0);
  return so;
}

int checkSoNguyenDuong(char cc[])
{
  int so,buff;
  char c;
  do
    {
      __fpurge(stdin);
      printf("%s:",cc);
      buff=scanf("%d%c",&so,&c);
      if(buff!=2||c!='\n'||so<0) printf("Ban da nhap sai cu phap\n");
    }while(buff!=2||c!='\n'||so<0);
  return so;
}


PointerType *TimPrev(PointerType *diaChi, PointerType *ds)
{
  PointerType *TempNode,*prev;
  TempNode=ds;
  while(TempNode!=diaChi)
    {
      prev=TempNode;
      TempNode=TempNode->Next;
    }
  return prev;
}

int SoPhanTu(PointerType *ds)
{
  PointerType *TempNode;
  int n;
  n=0;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      n++;
      TempNode=TempNode->Next;
    }
  return n;
}
/*
void SWAP(PointerType *ds,PointerType *diaChi1,PointerType *diaChi2)
{
  PointerType *prev1,*prev2,*Temp;
  prev1=TimPrev(diaChi1,ds);
  prev2=TimPrev(diaChi2,ds);
  prev2->Next=diaChi1;
  Temp=diaChi1->Next;
  diaChi1->Next=diaChi2->Next;
  prev1->Next=diaChi2;
  diaChi2->Next=Temp;
}

void SapXep(PointerType *ds)
{
  int i,j;
  int n;
  PointerType *TempNode1,*TempNode2;
  PointerType *diaChi1,*diaChi2;
  //TempNode1=ds;
  //n=SoPhanTu(ds);
  for(TempNode1=ds;TempNode1!=NULL;TempNode1=TempNode1->Next)
    {
      for(TempNode2=TempNode1;TempNode2!=NULL;TempNode2=TempNode2->Next)
	{
	  diaChi1=TempNode1;
	  diaChi2=TempNode2;
	  if(diaChi1->Inf.gia > diaChi2->Inf.gia)
	    SWAP(ds,diaChi1,diaChi2);
	}
    }
    }
*/

int TimMin(PointerType *ds)
{
  int min;
  PointerType *TempNode;
  TempNode=ds;
  min=ds->Inf.gia;
  // printf("%d\n",min);
  while(TempNode!=NULL)
    {
      if(TempNode->Inf.gia<min)
	min=TempNode->Inf.gia;
      TempNode=TempNode->Next;
    }
  return min;
}

PointerType *TimDiaChiCuaMin(PointerType *ds,int min)
{
  PointerType *TempNode;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      if(TempNode->Inf.gia==min)
	return TempNode;
      TempNode=TempNode->Next;
    }
  return NULL;
}
/*
void SapXep(PointerType *ds)
{
  PointerType *TempNode,*TN,*f;
  int min;
  int i;
  TN=ds;
  while(TN!=NULL)
    {
      f=TN;
      min=TimMin(TN);
      printf("\n%d\n",min);
      TempNode=TimDiaChiCuaMin(TN,min);
      if(TN==ds)
	ds=InsertToHead(TN,TempNode->Inf);
      else
	f=InsertToHead(TN,TempNode->Inf);
      if(TempNode->Next==NULL)
	DeleteLast(ds);
      else
	if(TempNode==f||TempNode==ds)
	  if(TN==ds)
	    DeleteHead(ds);
	  else
	    DeleteHead(f);
	else
	  Delete(TimPrev(TempNode,ds));
      Print(ds);
      TN=TN->Next;
    }
}
void SapXep(PointerType *ds)
{
  PointerType *TempNode,*TN;
  int min;
  int i;
  if(ds!=NULL)
    {
      Print(ds);
      min=TimMin(ds);
      printf("\n%d\n",min);
      TempNode=TimDiaChiCuaMin(ds,min);
      ds=InsertToHead(ds,TempNode->Inf);
      if(TempNode->Next=NULL)
	DeleteLast(ds);
      else
	if(TempNode==ds)
	  DeleteHead(ds);
	else
	  {
	    TN=TimPrev(TempNode,ds);
	    printf("\nPrev:%d\n",TN->Inf.gia);
	    Delete(TN);
	  }
      Print(ds);
      SapXep(ds->Next);
    }
}
*/

void SapXep(PointerType *ds)
{
  PointerType *diaChi1,*diaChi2;
  SanPham temp;
  for(diaChi1=ds;diaChi1!=NULL;diaChi1=diaChi1->Next)
    for(diaChi2=diaChi1;diaChi2!=NULL;diaChi2=diaChi2->Next)
      if(diaChi1->Inf.gia>diaChi2->Inf.gia)
	{
	  temp=diaChi1->Inf;
	  diaChi1->Inf=diaChi2->Inf;
	  diaChi2->Inf=temp;
	}
}


void SapXepTen(PointerType *ds)
{
  PointerType *diaChi1,*diaChi2;
  SanPham temp;
  for(diaChi1=ds;diaChi1!=NULL;diaChi1=diaChi1->Next)
    for(diaChi2=diaChi1;diaChi2!=NULL;diaChi2=diaChi2->Next)
      if(strcmp(diaChi1->Inf.ten,diaChi2->Inf.ten)<0)
	{
	  temp=diaChi1->Inf;
	  diaChi1->Inf=diaChi2->Inf;
	  diaChi2->Inf=temp;
	}
}

int TongTien(PointerType *ds)
{
  PointerType *TempNode;
  int s;
  s=0;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      s=s+TempNode->Inf.gia*TempNode->Inf.soluong;
      TempNode=TempNode->Next;
    }
  return s;
}

void copy(PointerType *dscopy,PointerType *ds)
{
  PointerType *TempNode;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      dscopy=InsertToHead(dscopy,TempNode->Inf);
      TempNode=TempNode->Next;
    }
}
int ham5(PointerType *ds)
{
  PointerType *TempNode1,*TempNode2;
  int dem,dieuKien;
  dem=0;dieuKien=1;
  TempNode1=ds->Next;TempNode2=ds;
  while(TempNode1!=NULL)
    {
      if(TempNode2->Inf.gia==TempNode1->Inf.gia&&dieuKien==1)
	{
	  dem++;
	  dieuKien=0;
	}
      else
	if(TempNode2->Inf.gia!=TempNode1->Inf.gia)
	  dieuKien=1;
      TempNode2=TempNode1;
      TempNode1=TempNode1->Next;
    }
  return dem;
}

void ham6(PointerType *ds)
{
  PointerType *TempNode1,*TempNode2;
  int dem,dieuKien;
  dem=0;dieuKien=0;
  TempNode1=ds->Next;TempNode2=ds;
  printf("Cac ten trung nhau la:\n");
  while(TempNode1!=NULL)
    {
      if(strcmp(TempNode2->Inf.ten,TempNode1->Inf.ten)==0)
	{
	  //printf("%s\n",TempNode2->Inf.ten);
	  printf("%p %-5d%-10d%-5d%-10s\n",TempNode2,TempNode2->Inf.maSP,TempNode2->Inf.gia,TempNode2->Inf.soluong,TempNode2->Inf.ten);
	  dieuKien=1;
	}
      else
	{
	if(dieuKien==1)
	  	  printf("%p %-5d%-10d%-5d%-10s\n",TempNode2,TempNode2->Inf.maSP,TempNode2->Inf.gia,TempNode2->Inf.soluong,TempNode2->Inf.ten);
	dieuKien=0;
	  
	}
      TempNode2=TempNode1;
      TempNode1=TempNode1->Next;
    }
}

int main()
{
  int i,j,k;
  int n;
  char str[Max];
  n=0;
  SanPham sanPham;
  PointerType *ds=NULL,*dscopy=NULL;
  PointerType *TempNode;
  int thoat,luaChon;
  thoat=0;
  FILE *fptr;
  fptr=fopen("sanpham.txt","w+");
  do
    {
      luaChon= menuVaLuaChon(1,7);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  printf("Nhap vao ma san pham:");
	  scanf("%d",&sanPham.maSP);
	  n=1;
	  while(1)
	    {
	      if(n!=1)
		sanPham.maSP=checkMa(sanPham.maSP,"Nhap vao ma san pham:");
	      if(sanPham.maSP==0) break;
	      printf("Nhap vao ten san pham:");
	      __fpurge(stdin);
	      gets(sanPham.ten);
	      __fpurge(stdin);
	      sanPham.gia=checkSoNguyenDuong("Nhap vao gia san pham:");
	      sanPham.soluong=checkSoNguyenKhongAm("Nhap vao so luong san pham:");
	      n=0;
	      printf("\n"); fprintf(fptr,"%-5d%-10d%-5d%-10s\n",sanPham.maSP,sanPham.gia,sanPham.soluong,sanPham.ten);
	    }
	    break;
	case 2:
	  //ham2
	  fclose(fptr);
	  fptr=fopen("sanpham.txt","r");
	  while(fscanf(fptr,"%d %d %d",&sanPham.maSP,&sanPham.gia,&sanPham.soluong)!=EOF)
	    {
	      fgets(sanPham.ten,100,fptr);
	      sanPham.ten[strlen(sanPham.ten)-1]='\0';
	      ds=InsertToHead(ds,sanPham);
	      printf("%p %-5d%-10d%-5d%-10s\n",ds,sanPham.maSP,sanPham.gia,sanPham.soluong,sanPham.ten);
	    }
	  // Print(ds);
	  break;
	case 3:
	  //ham3
	  SapXep(ds);
	  Print(ds);
	  break;
	case 4:
	  //ham4
	  printf("Tong tien cac san pham la %d\n",TongTien(ds));
	  break;
	case 5:
	  //ham5
	  printf("So luong nhom cung gia la %d\n",ham5(ds));
	  break;
	case 6:
	  //ham6
	  // copy(dscopy,ds);
	  // PointerType *TempNode;
	  TempNode=ds;
	  while(TempNode!=NULL)
	    {
	      dscopy=InsertToHead(dscopy,TempNode->Inf);
	      TempNode=TempNode->Next;
	    }
  // printf("\n.\n");
	  Print(dscopy);
	  SapXepTen(dscopy);
	  Print(dscopy);
	  //  printf("\n.\n");
	  ham6(dscopy);
	  break;
	case 7:
	  thoat=1;
	  break;
	}	
    }while(thoat!=1);
}
 
