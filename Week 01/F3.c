#include <stdio.h>

int main()
{
  char c[100];
  FILE *fptr1,*fptr2;
  fptr1=fopen("lab.txt","r");
  fptr2=fopen("lab3.txt","w");
  while(!feof(fptr1))
    {
      fgets(c,100,fptr1);
      fputs(c,fptr2);
    }
  fclose(fptr1);
  fclose(fptr2);
}
