#include <stdio.h>
typedef int element;

//1. sap xep chen
void sapXepChen(element list[],int n);

//2. sap xep chon
void sapXepChon(element a[],int n);

//3. sap xep vun dong
void adjust(element list[],int root,int n);
void sapXepVunDong( element list[],int n);

//4. quick sort
void SWAP(element *a, element *b);
void quickSort(element list[], int left, int right);

//5. sap xep tron
void merge(int arr[], int l, int m, int r);
void sapXepTron(element arr[], int l, int r);
