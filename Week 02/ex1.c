#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcat( char s1[],char s2[])
{
  char *s3;
  int n;
  n=strlen(s1)+strlen(s2);
  s3=(char*)malloc(n*sizeof(char));
  strcpy(s3,strcat(s1,s2));
  return s3;
}

int main()
{
  char s1[100],s2[100];
  strcpy(s1,"Mot");
  strcpy(s2,"Hai");
  printf("%s\n",my_strcat(s1,s2));
}
