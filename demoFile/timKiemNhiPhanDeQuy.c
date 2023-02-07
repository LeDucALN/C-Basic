#include <stdio.h>

int binSearch(int List[],int Target,int Lo,int Hi)
{
  int Mid;
  if(Hi<Lo) return -1;
  else
    {
      Mid=(Lo+Hi)/2;
      if(List[Mid]==Target)
	return Mid;
      else if(Target<List[Mid])
	return binSearch(List,Target,Lo,Mid-1);
      else return binSearch(List,Target,Mid+1,Hi);
    }
  return -1;
}

int main()
{
  int a[]={1,2,3,4,5,6,7,8};
  int n,k;
  printf("Nhap vao n:");
  scanf("%d",&n);
  k=binSearch(a,n,0,9);
  if(k==-1) printf("Khong tim duoc\n");
  else printf("%d\n",k);
}
