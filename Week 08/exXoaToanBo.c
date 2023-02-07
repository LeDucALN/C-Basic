#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
void freetree(treetype Tree)
{
  if(Tree!=NULL)
    {
      freetree(Tree->left);
      freetree(Tree->right);
      free((void*)Tree);
    }
}


void InsertNode( elmType x, treetype *Root)
{
  if(*Root==NULL)
    {
      *Root=(node_Type*)malloc(sizeof(node_Type));
      (*Root)->element=x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if(x<(*Root)->element) InsertNode(x,&(*Root)->left);
  else if(x>(*Root)->element) InsertNode(x,&(*Root)->right);
}


void prettyprint(treetype tree,char *prefix)
{
  char *prefixend=prefix+strlen(prefix);
  if (tree!=NULL)
    {
      printf("%04d",tree->element);
      if(tree->left!=NULL)
	if (tree->right==NULL)
	  {
	    printf("\304");
	    strcat(prefix," ");
	  }
	else
	  {
	    printf("\302");
	    strcat(prefix,"\263 ");
	  }
      prettyprint(tree->left,prefix);
      *prefixend='\0';
      if (tree->right!=NULL)
	if (tree->left!=NULL)
	  {
	    printf("\n%s",prefix);printf("\300");

	  }
	else
	  printf("\304");
      strcat(prefix," ");
      prettyprint(tree->right,prefix);
    }
}

int main()
{
  int i,n,m;
  elmType Data;
  treetype T;
  MakeNullTree(&T);
  srand(time(NULL));
  for(i=0;i<10;i++)
    {
      Data=rand()%10;
      //printf("%d\n",Data);
      InsertNode(Data,&T);
    }
  freetree(T);

}
