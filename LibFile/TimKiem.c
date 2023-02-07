#include <stdio.h>
#include "TimKiem.h"

//1. tim kiem linh canh
int timKiemLinhCanh (int M[],int N, int X)
{
  int k = 0; M[N]=X;
  while (M[k] != X)
    k++;
  if(k==N) return -1;
  return k+1;
}

//2. tim kiem nhi phan
int timKiemNhiPhan(int List[],int Target,int Size)
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

//3. tim kiem nhi phan de quy
int timKiemNhiPhanDeQuy(int List[],int Target,int Lo,int Hi)
{
  int Mid;
  if(Hi<Lo) return -1;
  else
    {
      Mid=(Lo+Hi)/2;
      if(List[Mid]==Target)
	return Mid;
      else if(Target<List[Mid])
	return timKiemNhiPhanDeQuy(List,Target,Lo,Mid-1);
      else return timKiemNhiPhanDeQuy(List,Target,Mid+1,Hi);
    }
  return -1;
}

//4. tim kiem sap xep chuyen len dau

int timKiemSXChuyenLenDau(int key,int r[],int n)
{
  int i,j;
  int tempr;
  for(i=0;i<n;i++)
    if(key==r[i])
      {
	if(i>0)
	  {
	    tempr=r[i];
	    for(j=0;j<i;j++)
	      r[j+1]=r[j];
	    r[0]=tempr;
	  }
	return i;
      }
    return -1;
}

//5. tim kiem sap xep doi cho
int timKiemSXDoiCho(int key,int r[],int n)
{
  int i,j;
  int tempr;
  for(i=0;i<n;i++)
    if(key==r[i])
      {
	if(i>0)
	  {
	    tempr=r[i];
	    r[i]=r[i-1];
	    r[--i]=tempr;
	  }
	return i;
      }
   return -1;
}

//6. tim kiem tuan tu
int timKiemTuanTu( int M[], int N,int X)
{
  int k=0;
  while(M[k]!=X&&k<N)
    k++;
  if(k<N) return k;
  return -1;
}
