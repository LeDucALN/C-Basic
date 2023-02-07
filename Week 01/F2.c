#include <stdio.h>

int main()
{
  char c;
  FILE *fptr1,*fptr2;
  fptr1=fopen("lab.txt","r");
  fptr2=fopen("lab2.txt","w+");
  while(!feof(fptr1))
    {
      c=fgetc(fptr1);
      if(c>'a'&&c<'z') c=c-'a'+'A';
      else if(c>'A'&&c<'Z') c=c-'A'+'a';
      fputc(c,fptr2);
    }
  fclose(fptr1);
  fclose(fptr2);
}
