#include <stdio.h>

typedef int element;
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

int main()
{}
