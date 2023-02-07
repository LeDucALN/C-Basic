#include <stdio.h>

int search(int key,int r[],int n)
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

int main()
{}
