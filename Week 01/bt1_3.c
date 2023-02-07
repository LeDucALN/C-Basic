#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void thayThe(char a[],char b, char c)
{
  int n;
  int i;
  n=strlen(a);
  for(i=0;i<n;i++)
    {
      if(a[i]==b)
	a[i]=c;
    }
}

int main()
{
  char a[100];
  char b,c;
  printf("Nhap xau va ki tu:");
  __fpurge(stdin);
  scanf("%s %c %c",a,&b,&c);
  __fpurge(stdin);
  // printf("%s\n%c\n%c\n",a,b,c);;
  thayThe(a,b,c);
  printf("Xau moi la %s\n",a);
}
