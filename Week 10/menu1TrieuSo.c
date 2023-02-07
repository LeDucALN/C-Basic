#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define Max 1000000
typedef int element;

//1,in menu va nhap lua chon
int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Tao data");
  printf("|%5d|%-50s|\n",2,"Sap xep noi bot");
  printf("|%5d|%-50s|\n",3,"Sap xep chen");
  printf("|%5d|%-50s|\n",4,"Sap xep chon");
  printf("|%5d|%-50s|\n",5,"Sap xep vun dong");
  printf("|%5d|%-50s|\n",6,"Quyt");
  
  
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

//2, sap xep NGUYEN giam dan
void sapXepNoiBotGiamDan( int a[], int size)
{
  int i,j,tmp;
  for(i=0;i<size;i++)
    {
      for(j=size;j>i;j--)
	{
	  if(a[i]<a[j])
	    {
	      tmp=a[i];
	      a[i]=a[j];
	      a[j]=tmp;
	    }
	}
    }
}

//3, sap xep NGUYEN lon dan
void sapXepNoiBotLonDan( int a[], int size)
{
  int i,j,tmp;
  for(i=0;i<size;i++)
    {
      for(j=size;j>i;j--)
	{
	  if(a[i]>a[j])
	    {
	      tmp=a[i];
	      a[i]=a[j];
	      a[j]=tmp;
	    }
	}
    }
}

//4. Sap xep chen
void sapXepChen(element list[],int n)
{
  int i,j;
  element next;
  for(i=1;i<n;i++)
    {
      next =list[i];
      for(j=i-1;j>=0&&next<list[j];j--)
	list[j+1]=list[j];
      list[j+1]=next;
    }
}

//5. Sap xep chon
void sapXepChon(element a[],int n)
{
  int i,j,min,tmp;
  for(i=0;i<n-1;i++)
    {
      min=i;
      for(j=i+1;j<n;j++)
	if(a[j]<a[min])
	    min=j;
	    tmp=a[i];
	    a[i]=a[min];
	    a[min]=tmp;
	  
    }
}

//6. Sap xep vun dong
void adjust(element list[],int root,int n)
{
  int child,rootkey;
  element temp;
  temp=list[root];
  rootkey=list[root];
  child=2*root;
  while(child<=n)
    {
      if((child<n)&&(list[child]<list[child+1]))
	child++;
      if(rootkey>list[child]) break;
      else
	{
	  list[child/2]=list[child];
	  child*=2;
	}
    }
  list[child/2]=temp;
}

void sapXepVunDong( element list[],int n)
{
  int i,j;
  element temp;
  for(i=n/2;i>0;i--)
    adjust(list,i,n);
  for(i=n-1;i>0;i--)
    {
      {
	temp=list[1];
	list[1]=list[i+1];
	list[i+1]=temp;
      }
      adjust(list,1,i);
    }
}

int main()
{

  int thoat,luaChon;
  int mang[Max];
  int i;
  clock_t tstart,tfinish;
  float tcomp;
  thoat=0;
  do
    {
      luaChon= menuVaLuaChon(1,6);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  srand(time(NULL));
	  for(i=0;i<Max;i++)
	    mang[i]=rand()%Max;
	    break;
	case 2:
	  //ham2
	  tstart=clock();
	  sapXepNoiBotLonDan(mang,Max);
	  tfinish=clock();
	  tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
	  printf("Thoi gian chay la:%f\n",tcomp);
	  break;
	case 3:
	  //ham3
	  tstart=clock();
	  sapXepChen(mang,Max);
	  tfinish=clock();
	  tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
	  printf("Thoi gian chay la:%f\n",tcomp);
	  break;
	case 4:
	  //ham4
	  tstart=clock();
	  sapXepChon(mang,Max);
	  tfinish=clock();
	  tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
	  printf("Thoi gian chay la:%f\n",tcomp);
	  break;
	case 5:
	  //ham5
	  tstart=clock();
	  sapXepVunDong(mang,Max);
	  tfinish=clock();
	  tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
	  printf("Thoi gian chay la:%f\n",tcomp);
	  break;
	case 6:
	  thoat=1;
	  break;
	}	
    }while(thoat!=1);
}
