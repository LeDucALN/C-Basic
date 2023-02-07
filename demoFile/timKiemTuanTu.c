#include <stdio.h>

int LinearSearch( int M[], int N,int X)
{
  int k=0;
  while(M[k]!=X&&k<N)
    k++;
  if(k<N) return k;
  return -1;
}

int main()
{}
