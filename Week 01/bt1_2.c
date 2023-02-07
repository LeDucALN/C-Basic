#include <stdio.h>
#include <string.h>
#define Max 100

int soSanh2Mang(int a[],int b[])
{
  int i;
  for(i=0;i<Max;i++)
    if(a[i]!=b[i]) return 0;
  return 1;
}

int main()
{
  int i,m,n;
  printf("Xau 1 co so phan tu la:");
  scanf("%d",&m);
  printf("Xau 2 co so phan tu la:");
  scanf("%d",&n);
  int a[Max],b[Max];
  for(i=0;i<m;i++)
    {
      printf("Nhap vao phan tu thu %d cua xau 1:",i+1);
      scanf("%d",&a[i]);
    }
  for(i=m;i<Max;i++)
    a[i]=0;
  for(i=0;i<n;i++)
    {
      printf("Nhap vao phan tu thu %d cua xau 2:",i+1);
      scanf("%d",&b[i]);
    }
  for(i=n;i<Max;i++)
    b[i]=0;
  if(soSanh2Mang(a,b)==0) printf("Khong giong\n");
  else printf("Giong\n");
}
