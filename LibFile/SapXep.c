#include <stdio.h>
#include "SapXep"

//1. sap xep chen
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

//2. sap xep chon
void sapXepChon(element a[],int n)
{
  int i,j,min,tmp;
  for(i=0;i<n-1;i++)
    {
      min=i;
      for(j=i+1;j<n;j++)
	if(a[j]<a[min])
	    min=j;
	    tmp=a[i];
	    a[i]=a[min];
	    a[min]=tmp;	  
    }
}

//3. sap xep vun dong
void adjust(element list[],int root,int n)
{
  int child,rootkey;
  element temp;
  temp=list[root];
  rootkey=list[root];
  child=2*root;
  while(child<=n)
    {
      if((child<n)&&(list[child]<list[child+1]))
	child++;
      if(rootkey>list[child]) break;
      else
	{
	  list[child/2]=list[child];
	  child*=2;
	}
    }
  list[child/2]=temp;
}

void sapXepVunDong( element list[],int n)
{
  int i,j;
  element temp;
  for(i=n/2;i>0;i--)
    adjust(list,i,n);
  for(i=n-1;i>0;i--)
    {
      {
	temp=list[1];
	list[1]=list[i+1];
	list[i+1]=temp;
      }
      adjust(list,1,i);
    }
}

//4. quick sort
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

//5. sap xep tron
void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
/* tạo các mảng tạm thời*/
  int L[n1], R[n2];
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
      if (L[i] <= R[j])
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

void sapXepTron(element arr[], int l, int r)
{
  if (l < r)
    {
      int m = l+(r-l)/2;
      sapXepTron(arr, l, m);
      sapXepTron(arr, m+1, r);
      merge(arr, l, m, r);
    }
}


