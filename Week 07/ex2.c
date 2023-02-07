#include <stdio.h>
#define Max 100
int count=0;

int binSearch(int List[],int Target,int Size)
{
  int Mid, Lo=0,Hi=Size-1;
  while(Lo<=Hi)
    {
      Mid=(Lo+Hi)/2;
      if(List[Mid]==Target)
	{
	  count++;
	  return Mid;
	}
      else if(Target<List[Mid])
	{
	  count=count+2;
	  Hi=Mid-1;
	}
      else
	{
	  count=count+2;
	  Lo=Mid+1;
	}
    }
  return -1;
}

int main()
{
  int a[Max];
  int i,n,k;
  for(i=0;i<Max;i++)
    a[i]=i;
  
  printf("Nhap vao n:");
  scanf("%d",&n);
  k=binSearch(a,n,Max);
  if(k==-1) printf("Not found\n");
  else printf("Vi tri trong mang la a[%d]\n",k);
  printf("So phep toan:%d\n",count);
}
