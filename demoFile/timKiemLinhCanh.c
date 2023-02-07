#include <stdio.h>

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
  int a[]={1,2,3,4,5,6,7};
  int n;
  n=timKiemLinhCanh(a,7,2);
  if(n==-1) printf("Khong tim duoc\n");
  else printf("O vi tri thu:%d\n",n);
}
