#include <stdio.h>
typedef int element;

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

void mergeSort(element arr[], int l, int r)
{
  if (l < r)
    {
      int m = l+(r-l)/2;
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
      merge(arr, l, m, r);
    }
}

int main()
{}
