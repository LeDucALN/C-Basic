#include <stdio.h>
#include <string.h>
#include <math.h>
#define z 22

int intergerCast(char s[])
{
  int i,n;
  int key;
  key=0;
  n=strlen(s);
  for(i=0;i<n;i++)
    key=key+s[i];
  return key;
}

long daThuc(char s[])
{
  int i,n;
  long key;
  key=0;
  n=strlen(s);
  for(i=0;i<n;i++)
    key=key+pow(z,i)*s[i];
  return key;
}

int tongCacThanhPhan(long i)
{
  return (int) ((i>>32)+(int)i);
}

int main()
{}
