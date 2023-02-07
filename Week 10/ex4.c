#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#define SoLuong 10

typedef char element;
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

int main()
{
  char a[SoLuong];
  int i;
  for(i=0;i<SoLuong;i++)
    {
      scanf("%c",&a[i]);
    }
  
  for(i=0;i<SoLuong;i++)
    {
      printf("%c",a[i]);
    }
  printf("\n");
  sapXepChen(a,SoLuong);
  
  for(i=0;i<SoLuong;i++)
    {
      printf("%c",a[i]);
    }
  printf("\n");
}
