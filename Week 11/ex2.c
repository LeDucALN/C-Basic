#include <stdio.h>
#include <time.h>
#define Max 100

typedef char element;
void sapXepChen(element list[],int n)
{
  int i,j;
  element next;
  for(i=1;i<n;i++)
    {
      next =list[i];
      for(j=i-1;j>=0&&next<list[j];j--)
	list[j+1]=list[j];
      list[j+1]=next;
    }
}

void SWAP(element *a, element *b)
{
  element temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void quickSort(element list[], int left, int right)
{
  char pivot;
  int i, j;
  if(left < right)
    {
      i = left;
      j = right+1;
      pivot = list[left];
      do
	{
	  do i++; while(list[i]< pivot);
	  do j--; while(list[j] > pivot);
	  if (i < j) SWAP(&list[i],&list[j]);
	} while (i < j);
      SWAP(&list[left],&list[j]);
      quickSort(list, left, j-1);
      quickSort(list, j+1, right);
    }
}

int main()
{
  int x;
  int i,j;
  char s[Max];
  clock_t tstart,tfinish;
  float tcomp;
  FILE *fptr;
  fptr=fopen("file.txt","r");
  printf("Nhap vao x:");
  scanf("%d",&x);
  for(i=0;i<Max;i++)
   s[i]= fgetc(fptr);
  if(x>Max)
    {
      tstart=clock();
      quickSort(s,0,Max-1);
      tfinish=clock();
      tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
    }
  else
    {
      tstart=clock();
      sapXepChen(s,Max);
      tfinish=clock();
      tcomp=(float)(tfinish-tstart)/CLOCKS_PER_SEC;
    }
    sapXepChen(s,Max);
  for(i=0;i<Max;i++)
    printf("%c\n",s[i]);
  printf("Thoi gian chay la:%f\n",tcomp);
  fclose(fptr);
}
