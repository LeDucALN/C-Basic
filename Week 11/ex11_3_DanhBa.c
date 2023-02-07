#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
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

void mergeTheoTen(element arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
/* tạo các mảng tạm thời*/
  element L[n1], R[n2];
/* Chép dữ liệu vào các mảng tạm thười arrays L[] và R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];
/* Trộn các mảng tạm thời trở lại vào arr[l..r]*/
  i = 0; // Khởi tạo chỉ số cho mảng con thứ 1
  j = 0; // Khởi tạo chỉ số cho mảng con thứ 2
  k = l; // Khởi tạo chỉ số cho mảng con được trộn
  while (i < n1 && j < n2)
    {
      if (strcmp(L[i].name,R[j].name)<=0)
	{
	  arr[k] = L[i];
	  i++;
	}
      else
	{
	  arr[k] = R[j];
	  j++;
	}
      k++;
    }
/* Chép các phần tử còn lại của L[], nếu còn */
  while (i < n1)
    {
      arr[k] = L[i];
      i++;
      k++;
    }
/* Chép các phần tử còn lại của R[], nếu còn */
  while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
}

void mergeSortTheoTen(element arr[], int l, int r)
{
  if (l < r)
    {
      int m = l+(r-l)/2;
      mergeSortTheoTen(arr, l, m);
      mergeSortTheoTen(arr, m+1, r);
      mergeTheoTen(arr, l, m, r);
    }
}

void In(element a[], int size)
{
  int i;
  for(i=0;i<size;i++)
    {
      printf("%d\n",i+1);
      printf("%s",a[i].name);
      printf("%s",a[i].tel);
      printf("%s\n",a[i].mail);
    }
}
int main()
{
  int i;
  char str[Max];
  int soDanhBa;
  element danhBa[Max];
  soDanhBa=0;i=0;
  FILE *fptr;
  fptr=fopen("danhBa.txt","r");
  while(!feof(fptr))
    {
      fgets(str,100,fptr);
      fgets(danhBa[i].name,100,fptr);
      // danhBa[i].name[strlen(danhBa[i].name)-1]='\0';
      // printf("\n%s\n",danhBa[i].name);
      fgets(danhBa[i].tel,100,fptr);
      // danhBa[i].tel[strlen(danhBa[i].tel)-1]='\0';
      fgets(danhBa[i].mail,100,fptr);
      //danhBa[i].mail[strlen(danhBa[i].mail)-1]='\0';
      soDanhBa++;
      i++;
    }
  //printf("%d\n",soDanhBa);
  printf("thu tu ban dau:\n");
  In(danhBa,soDanhBa-1);
  printf("\n");
  mergeSortTheoTen(danhBa,0,soDanhBa-2);
  printf("\nSau khi sap xep:\n");
  In(danhBa,soDanhBa-1);
  printf("\n");
}
