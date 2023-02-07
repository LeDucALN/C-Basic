#include <stdio.h>
#include <string.h>
#define M 10
#define NULLKEY -1

// size of hash table

struct node
{
  int key;
};

//Declare hash table as an array
struct node hashtable[M];
int NODEPTR;
int N = 0;

int hashfunc(int key)
{
  return(key% 10); // or any number
}

void initialize( )
{
  int i;
  for(i=0;i<M;i++)
    hashtable[i].key=NULLKEY;
  N=0;
  //so nut hien co khoi dong bang 0
}

int full( )
{
  return (N==M-1 ? 1: 0);
}

int empty( )
{
  return (N==0 ? 1: 0);
}

int search(int k)
{
  int i;
  i=hashfunc(k);
  while(hashtable[i].key!=k && hashtable[i].key !=NULLKEY)
    {
      //rehash :fi(key)=f(key)+1) % M
      i=i+1;
      if(i>=M) i=i-M;
    }
  if(hashtable[i].key==k) // found
    return i;
  else // not found
    return M;
}

int insert(int k)
{
  int i, j;
  if(full())
    {
      printf("\n Hash table is full. Can not insert the key %d ",k);
      return;
    }
  i=hashfunc(k);
  while(hashtable[i].key !=NULLKEY)
    {
      // Rehash
      i ++;
      if(i>M) i= i-M;
    }
  hashtable[i].key=k;
  N=N+1;
  return i;
}
  
void Remove(int i)
{
  int j, r, a, cont=1;
  do
    {
      hashtable[i].key = NULLKEY;
      j = i;
      do
	{
	  i=i+1;
	  if(i>=M)
	    i=i-M;
	  if(hashtable[i].key == NULLKEY)
	    cont = 0;
	  else
	    {
	      r = hashfunc(hashtable[i].key);
	      a = (j<r && r<=i)||(r<=i && i<j)||(i<j && j<r);
	    }
	}while (cont && a);
      if(cont)
	hashtable[j].key=hashtable[i].key;
    }while(cont);
}

int main()
{
  int i,j;
  initialize( );
  
  for(i=0;i<5;i++)
    {
      printf("Nhap vao n:");
      scanf("%d",&j);
      insert(j);
    }
  for(i=0;i<10;i++)
    {
      printf("Cuc %d: %d\n",i,hashtable[i].key);
    }
  printf("SEARCH:");
  scanf("%d",&i);
  printf("%d",search(i));
  printf("\nREMOVE:");
  scanf("%d",&i);
  Remove(i);
  
  for(i=0;i<10;i++)
    {
      printf("Cuc %d: %d\n",i,hashtable[i].key);
    }
}