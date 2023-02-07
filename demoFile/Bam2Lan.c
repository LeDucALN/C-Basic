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
  return (key%M);
}
//Hàm băm thứ 2
int hashfunc2(int key)
{
  return(M-2 - key%(M-2));
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
  int i, j ;
  i = hashfunc(k);
  j = hashfunc2 (k);
  while(hashtable[i].key!=k && hashtable[i].key !=NULLKEY)
    {
      //Băm lại
      i = (i+j) % M ;
    }
  if(hashtable[i].key==k) // found
    return i;
  else // not found
    return M;
}

int insert(int k)
{
  int i,j;
  if(full())
    {
      printf("\n Hash table is full. Can not insert the key %d ",k);
      return M;
    }
  if (search (k) < M)
    {
      printf("This key exist in the hash table") ;
      return M ;
    }
  i = hashfunc(k);
  j = hashfunc2(k);
  while(hashtable[i].key !=NULLKEY)
    {
      //Rehashing
      i = (i+j) % M;
    }
  hashtable[i].key=k;
  N=N+1;
  return i;
}

int main()
{}
