#include <stdio.h>
#define Max 10

int timKiemLinhCanh (int M[],int N, int X)
{
  int k = 0; M[N]=X;
  while (M[k] != X)
    k++;
  if(k==N) return -1;
  return k+1;
}

int main()
{
  int a[100];
  int b;
  int i;
  int viTri;
  for(i=0;i<Max;i++)
    {
      printf("Nhap vao so thu %d:",i+1);
      scanf("%d",&a[i]);
    }
  printf("Nhap vao so thu %d:",Max+1);
  scanf("%d",&b);
  viTri=timKiemLinhCanh(a,Max,b);
  if(viTri==-1)
    printf("0\n");
  else
    printf("Vi tri:%d\n",viTri);
}
