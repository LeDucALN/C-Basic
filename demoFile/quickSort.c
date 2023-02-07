#include <stdio.h>
typedef int element;

void SWAP(element *a, element *b)
{
  element temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void quickSort(element list[], int left, int right)
{
  int pivot, i, j;
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
{}
