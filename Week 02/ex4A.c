#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[])
{
  char str[200];
  FILE *fptr1,*fptr2;
  fptr1=fopen(argv[1],"r");
  fptr2=fopen(argv[2],"w+");
  while(!feof(fptr1))
    {
      fread(str,sizeof(char),200,fptr1);
      
      //str[strlen(str)+1]='\0';
      fwrite(str,sizeof(char),strlen(str),fptr2);
    }
  fclose(fptr1);
  fclose(fptr2);
}
