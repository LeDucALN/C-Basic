#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define Max 100

typedef struct
{
  int id;
  char Name[30];
  int diem;
  int Win;
  int Lose;
}DoiBong;

typedef DoiBong ElementType;
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
  printf("%5s%5s%-15s%-5s%-10s%-10s\n","ID"," ","Ten","Diem","SoBanWin","SoBanLose");
  while(TempNode!=NULL){
    printf("%5d%-20s%-5d%-10d%-10d\n",TempNode->Inf.id,TempNode->Inf.Name,TempNode->Inf.diem,TempNode->Inf.Win,TempNode->Inf.Lose);
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

PointerType *TimKiemID(PointerType *ds,int ID)
{
  PointerType *TempNode;
  TempNode=ds;
  while(TempNode!=NULL)
    {
      if(TempNode->Inf.id==ID)
	return TempNode;
      TempNode=TempNode->Next;
    }
  return NULL;
}

int TimMin(PointerType *ds)
{
  int min;
  PointerType *TempNode;
  TempNode=ds;
  min=ds->Inf.diem;
  // printf("%d\n",min);
  while(TempNode!=NULL)
    {
      if(TempNode->Inf.diem<min)
	min=TempNode->Inf.diem;
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
      if(TempNode->Inf.diem==min)
	return TempNode;
      TempNode=TempNode->Next;
    }
  return NULL;
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
}

int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"In thong tin cac doi bong");
  printf("|%5d|%-50s|\n",2,"In thong tin lich thi dau");
  printf("|%5d|%-50s|\n",3,"Cap nhat ket qua");
  printf("|%5d|%-50s|\n",4,"Thong ke");
  printf("|%5d|%-50s|\n",5,"Thoat");
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


int main()
{
  PointerType *ds=NULL;
  PointerType *diaChi=NULL,*diaChi1=NULL,*diaChi2=NULL;
  DoiBong doiBong;
  int diem1,diem2;
  int min;
  int thoat,luaChon;
  thoat=0;
  FILE *fptr1,*fptr2;
  int n;
  int i,j,k;
  int a,b;
  char str[Max];
  fptr1=fopen("bongda.txt","r");
  fptr2=fopen("copy.txt","w+");
  do
    {
      luaChon= menuVaLuaChon(1,5);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  fscanf(fptr1,"%d",&n);
	  fgets(str,100,fptr1);
	  for(i=0;i<n;i++)
	    {
	      fscanf(fptr1,"%d",&doiBong.id);
	      fgets(doiBong.Name,100,fptr1);
	      doiBong.Name[strlen(doiBong.Name)-1]='\0';
	      doiBong.diem=0;
	      doiBong.Win=0;
	      doiBong.Lose=0;
	      ds=InsertToHead(ds,doiBong);
	    }
	  k=n/2;
	  for(i=0;i<n-1;i++)
	    {
	      fgets(str,100,fptr1);
	      fputs(str,fptr2);
	      for(j=0;j<k;j++)
		{
		  fgets(str,100,fptr1);
		  fputs(str,fptr2);
		}
	    }
	  Print(ds);
	    break;
	case 2:
	  //ham2
	  fclose(fptr2);
	  fptr2=fopen("copy.txt","r");
	  for(i=0;i<n-1;i++)
	    {
	      fgets(str,100,fptr2);
	      printf("%s",str);
	      for(j=0;j<k;j++)
		{
		  fscanf(fptr2,"%d\t%d\n",&a,&b);
		  //printf("%d %d\n",a,b);
		  __fpurge(stdin);
		  diaChi1=TimKiemID(ds,a);
		  printf("%s\t",diaChi1->Inf.Name);
		  diaChi2=TimKiemID(ds,b);
		  printf("%s\n",diaChi2->Inf.Name);
		}
	    }
	  break;
	case 3:
	  //ham3
	  fclose(fptr2);
	  fptr2=fopen("copy.txt","r");
	  for(i=0;i<n-1;i++)
	    {
	      fgets(str,100,fptr2);	      
	      printf("Cap nhat ket qua Vong %d:\n",i+1);
	      printf("%s",str);
	      for(j=0;j<k;j++)
		{
		  fscanf(fptr2,"%d\t%d",&a,&b);
		  fgets(str,100,fptr2);
		  diaChi1=TimKiemID(ds,a);
		  printf("%s - ",diaChi1->Inf.Name);
		  diaChi2=TimKiemID(ds,b);
		  printf("%s:",diaChi2->Inf.Name);
		  __fpurge(stdin);
		  scanf("%d%*c%d",&diem1,&diem2);
		  __fpurge(stdin);
		  if(diem1>diem2)
		    {
		      diaChi1->Inf.diem=diaChi1->Inf.diem+3;
		    }
		      
		  else
		    if(diem1==diem2)
		      {
			diaChi1->Inf.diem=diaChi1->Inf.diem+1;
			diaChi2->Inf.diem=diaChi2->Inf.diem+1;
		      }
		    else
		      diaChi2->Inf.diem=diaChi2->Inf.diem+3;
		  diaChi1->Inf.Win=diaChi1->Inf.Win+diem1;
		  diaChi1->Inf.Lose=diaChi1->Inf.Lose+diem2;
		  diaChi2->Inf.Win=diaChi2->Inf.Win+diem2;
		  diaChi2->Inf.Lose=diaChi2->Inf.Lose+diem1;
		}
	    }
	  Print(ds);
	  break;
	case 4:
	  //ham4
	  min=TimMin(ds);
	  //printf("\n.\n");
	  //printf("%d\n",min);
	  diaChi=TimDiaChiCuaMin(ds,min);
	  //printf("%p\n",diaChi);
	  //printf("\n.\n");
	  printf("Doi bi loai la:\n");
	  printf("%5s%5s%-15s%-5s%-10s%-10s\n","ID"," ","Ten","Diem","SoBanWin","SoBanLose");
	  while(diaChi!=NULL)
	    {
	      printf("%5d%-20s%-5d%-10d%-10d\n",diaChi->Inf.id,diaChi->Inf.Name,diaChi->Inf.diem,diaChi->Inf.Win,diaChi->Inf.Lose);
	      if(diaChi==ds)
		ds=DeleteHead(ds);
	      else
		if(diaChi->Next==NULL)
		  ds=DeleteLast(ds);
		else
		  Delete(TimPrev(diaChi,ds));
	      diaChi=TimDiaChiCuaMin(ds,min);
	    }
	  printf("Cac doi con lai la:\n");
	  Print(ds);
	  break;
	case 5:
	  thoat=1;
	  break;
	}	
    }while(thoat!=1);
  fclose(fptr1);
  fclose(fptr2);
}
 

