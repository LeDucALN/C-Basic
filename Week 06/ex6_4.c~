#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <stdlib.h>
#define Max 50

int main()
{
  FILE *fptr;
  char s[Max],key[Max];
  
  fptr=fopen("text.txt","r");
  printf("Nhap vao xau can tim:");
  __fpurge(stdin);
  scanf("%s",key);
  __fpurge(stdin);
  // printf("%ld\n",strlen(key));
  while(!feof(fptr))
    {
      __fpurge(stdin);
      fscanf(fptr,"%s",s);
      __fpurge(stdin);
      if(strstr(s,key)!=NULL)
	{
	  printf("%s\n",s);
	}
     
    }
}
