#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{
  FILE *fptr;
  char str[100];
  fptr=fopen("class1EF.txt","r+");
  while(!feof(fptr))
    {
      fgets(str,100,fptr);
      //fputs("\n",fptr);
      __fpurge(stdin);
      printf("%s",str);
      //fprintf(fptr,"%s","\n");
      //fgets(str,100,fptr);
    }
  fclose(fptr);
}
