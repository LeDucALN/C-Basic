#include <stdio.h>
#include <string.h>

int main()
{
  char c;
  int count;
  char str[100];
  FILE *fptr1,*fptr2;
  fptr1=fopen("lab.txt","r");
  fptr2=fopen("lab4.txt","w+");
  while(!feof(fptr1))
    {
      count=0;
      fgets(str,100,fptr1);
      count=strlen(str);
      fprintf(fptr2,"%d ",count);
      fputs(str,fptr2);
    }
  fclose(fptr1);
  fclose(fptr2);
}
