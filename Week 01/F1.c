#include <stdio.h>

int main()
{
  char c;
  FILE *fptr1,*fptr2;
  fptr1=fopen("lab.txt","r");
  fptr2=fopen("labw.txt","w");
  while(!feof(fptr1))
    {
      c=fgetc(fptr1);
      fputc(c,fptr2);
    }
  fclose(fptr1);
  fclose(fptr2);
}
