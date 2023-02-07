#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int elmType;
typedef struct nodeType
{
  elmType element;
  struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

void MakeNullTree (treetype *T)
{
  (*T)=NULL;
}

//thu tu giua
void inorderprint( treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      printf("%4d\n",tree->element);
      inorderprint(tree->right);
    }
}

//thu tu sau
void postorderprint( treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      inorderprint(tree->right);
      printf("%4d\n",tree->element);
    }
}

//thu tu truoc
void preorderprint( treetype tree)
{
  if(tree!=NULL)
    {
      printf("%4d\n",tree->element);
      inorderprint(tree->left);
      inorderprint(tree->right);
    }
}

int main()
{}




