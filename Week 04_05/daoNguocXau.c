#include <stdio.h>
#include "stack.h"

int main()
{
  StackType stack;
  int i,d,k;
  int mang[Max];
  Initialize(stack);
  k=0;i=1;
  while(i!=0)
    {
      printf("Nhap so:");
      scanf("%d",&d);
      push(d,stack);
      printf("Nhap 0 neu muon dung lai:");
      scanf("%d",&i);
    }
  while(empty(stack)!=1)
    {
      mang[i]=pop(stack);
      i++;k++;
    }
  for(i=0;i<k;i++)
    {
      push(mang[i],stack);
    }
  while(empty(stack)!=1)
    {
      printf("%d\n",pop(stack));
    }
}
