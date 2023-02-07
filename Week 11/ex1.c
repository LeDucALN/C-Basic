#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define Max 100
#define MaxDanhBa 100
#define SoLuong 10

typedef struct DanhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;

typedef address element;

void SWAP(element *a, element *b)
{
  element temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void quickSortTheoTen(element list[], int left, int right)
{
  element pivot;
  int i, j;
  if(left < right)
    {
      i = left;
      j = right+1;
      pivot = list[left];
      do
	{
	  do i++; while(strcmp(list[i].name,pivot.name)<0);
	  do j--; while(strcmp(list[j].name,pivot.name)>0);
	  if (i < j) SWAP(&list[i],&list[j]);
	} while (i < j);
      SWAP(&list[left],&list[j]);
      quickSortTheoTen(list, left, j-1);
      quickSortTheoTen(list, j+1, right);
    }
}

int main()
{
  address danhBa[MaxDanhBa];
  int i;
  int ViTri;
  char str[Max],ten[Max];
  FILE *fptr1,*fptr2;
  fptr1=fopen("danhBa.txt","r");
  fptr2=fopen("danhBaTheoTen.txt","w+");
  for(i=0;i<SoLuong;i++)
    {
      fgets(str,100,fptr1);
      fgets(danhBa[i].name,100,fptr1);
      //printf("%s\n",danhBa[i].name);
      fgets(danhBa[i].tel,100,fptr1);
      //printf("%s\n",danhBa[i].tel);
      fgets(danhBa[i].mail,100,fptr1);     
      //printf("%s\n",danhBa[i].mail);
    }
  quickSortTheoTen(danhBa,0,SoLuong-1);
  for(i=0;i<SoLuong;i++)
    {
      //fputs("\n",fptr2);
      fprintf(fptr2,"%d\n",i+1);
      fputs(danhBa[i].name,fptr2);
      fputs(danhBa[i].tel,fptr2);
      fputs(danhBa[i].mail,fptr2);
    }
  fclose(fptr2);
  fclose(fptr1);
}
