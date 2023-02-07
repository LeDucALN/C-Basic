#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#define Max 100
#define SoLuong 10
#define SoLuongMax 100

typedef struct danhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;

int main()
{
  address DanhBa[SoLuongMax];
  int i;
  FILE *fptr1;
  fptr1=fopen("danhBa.txt","w+");
  for(i=0;i<SoLuong;i++)
    {
      printf("Nguoi dung %d\n",i+1);
      printf("Nhap vao ten:");
      __fpurge(stdin);;
      gets(DanhBa[i].name);
      // printf("\n%s %ld\n",DanhBa[i].name,strlen(DanhBa[i].name));
      //DanhBa[i].name[strlen(DanhBa[i].name)]='\0';
      __fpurge(stdin);
      printf("Nhap vao so dien thoai:");
      gets(DanhBa[i].tel);
      //DanhBa[i].tel[strlen(DanhBa[i].tel)]='\0';      
      __fpurge(stdin);
      //printf("\n%s %ld\n",DanhBa[i].tel,strlen(DanhBa[i].tel));     
      printf("Nhap vao mail:");
      gets(DanhBa[i].mail);
      //DanhBa[i].mail[strlen(DanhBa[i].mail)]='\0';
      __fpurge(stdin);
      // printf("\n%s %ld\n",DanhBa[i].mail,strlen(DanhBa[i].mail));
      
    }
  for(i=0;i<SoLuong;i++)
    {
      //fwrite(&i,sizeof(int),100,fptr1);
      fputs("\n",fptr1);
      fwrite(DanhBa[i].name,sizeof(char),strlen(DanhBa[i].name),fptr1);
      fputs("\n",fptr1);
      fwrite(DanhBa[i].tel,sizeof(char),strlen(DanhBa[i].tel),fptr1);
      fputs("\n",fptr1);
      fwrite(DanhBa[i].mail,sizeof(char),strlen(DanhBa[i].mail),fptr1);
      fputs("\n",fptr1);
    }
  fclose(fptr1);
}
