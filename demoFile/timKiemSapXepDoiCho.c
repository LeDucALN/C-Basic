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
	    r[i]=r[i-1];
	    r[--i]=tempr;
	  }
	return i;
      }
   return -1;
}

int main()
{}
