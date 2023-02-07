#include <stdio.h>
#define Max 100
int count=0;

int binSearch(int List[],int Target,int Lo,int Hi)
{
  int Mid;
  if(Hi<Lo) return -1;
  else
    {
      Mid=(Lo+Hi)/2;
      if(List[Mid]==Target)
	{
	  return Mid;
	}
      else if(Target<List[Mid])
	{
	  count=count+1;
	  return binSearch(List,Target,Lo,Mid-1);
	}
      else
	{
	  count=count+1;
	  return binSearch(List,Target,Mid+1,Hi);
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
  k=binSearch(a,n,0,Max-1);
  if(k==-1) printf("Not found\n");
  else printf("Vi tri trong mang la a[%d]\n",k);
  printf("So lan goi binsearch la:%d\n",count);
}
