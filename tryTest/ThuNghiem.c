#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio_ext.h>
#include <string.h>
#define Max 100
typedef struct
{
  char Name[Max];
  int a;
  int b;
}HocSinh;
typedef HocSinh elmType;
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

int EmptyTree(treetype T)
{
  return T==NULL;
}

treetype LeftChild(treetype n)
{
  if(n!=NULL) return n->left;
  else return NULL;
}

treetype RightChild(treetype n)
{
  if(n!=NULL) return n->right;
  else return NULL;
}

node_Type *creat_node(elmType NewData)
{
  node_Type *N;
  N=(node_Type*)malloc(sizeof(node_Type));
  if(N!=NULL)
    {
      N->left = NULL;
      N->right = NULL;
      N->element = NewData;
    }
  return N;
}

int IsLeaf(treetype n)
{
  if(n!=NULL)
    return (LeftChild(n)==NULL)&&(RightChild(n)==NULL);
  else return -1;
}

int nb_nodes(treetype T)
{
  if(EmptyTree(T)) return 0;
  else return 1+nb_nodes(LeftChild(T))+nb_nodes(RightChild(T));
}

treetype creatfrom2( elmType v, treetype l,treetype r)
{
  treetype N;
  N=(node_Type*)malloc(sizeof(node_Type));
  N->element = v;
  N->left=l;
  N->right = r;
  return N;
}

treetype Add_Left(treetype *Tree, elmType NewData)
{
  node_Type *NewNode = creat_node(NewData);
  if(NewNode==NULL) return NewNode;
  if(*Tree == NULL)
    *Tree = NewNode;
  else
    {
      node_Type *Lnode=*Tree;
      while (Lnode->left != NULL)
	Lnode=Lnode->left;
      Lnode->left=NewNode;
    }
  return NewNode;
}

treetype Add_Right(treetype *Tree, elmType NewData)
{
  node_Type *NewNode = creat_node(NewData);
  if(NewNode==NULL) return NewNode;
  if(*Tree == NULL)
    *Tree = NewNode;
  else
    {
      node_Type *Rnode=*Tree;
      while (Rnode->right != NULL)
	Rnode=Rnode->right;
      Rnode->right=NewNode;
    }
  return NewNode;
}

int soLa(treetype Tree)
{
  if(Tree==NULL) return 0;
  else
    if(IsLeaf(Tree)==1) return 1;
    else
      return soLa(LeftChild(Tree))+soLa(RightChild(Tree));
}
/*
elmType  max( elmType a, elmType b)
{
  if(a>b) return a;
  else return b;
}

int chieuCao(treetype Tree)
{
  if(Tree==NULL) return 0;
  else
    if(IsLeaf(Tree)==1) return 1;
    else return max(chieuCao(LeftChild(Tree))+1,1+chieuCao(RightChild(Tree)));
}
*/
treetype Search(char *x,treetype Root)
{
  if(Root==NULL) return NULL;
  else if(strcmp(Root->element.Name,x)==0)
    return Root;
  else if(strcmp(Root->element.Name,x)<0)
    return Search(x,RightChild(Root));
  else
    return Search(x,LeftChild(Root));
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
  else if(strcmp(x.Name,(*Root)->element.Name)<0) InsertNode(x,&(*Root)->left);
  else if(strcmp(x.Name,(*Root)->element.Name)>0) InsertNode(x,&(*Root)->right);
}


elmType DeleteMin (treetype *Root)
{
  elmType k;
  if((*Root)->left==NULL)
    {
      k=(*Root)->element;
      (*Root)=(*Root)->right;
      return k;
    }
  else return DeleteMin(&(*Root)->left);
}
/*
void DeleteNode(elmType x,treetype *Root)
{
  if(*Root!=NULL)
    if(x<(*Root)->element) DeleteNode(x,&(*Root)->left);
    else if(x>(*Root)->element)
      DeleteNode(x,&(*Root)->right);
    else if(((*Root)->left==NULL)&&((*Root)->right==NULL))
      *Root=NULL;
    else if((*Root)->left==NULL)
      *Root=(*Root)->right;
    else if((*Root)->right==NULL)
      *Root=(*Root)->left;
    else (*Root)->element=DeleteMin(&(*Root)->right);
}
*/
void freetree(treetype Tree)
{
  if(Tree!=NULL)
    {
      freetree(Tree->left);
      freetree(Tree->right);
      free((void*)Tree);
    }
}

//thu tu giua
void inorderprint( treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      printf("%-20s%-5d%-5d\n",tree->element.Name,tree->element.a,tree->element.b);
      inorderprint(tree->right);
    }
}

/*
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
*/

int main()
{
  FILE *fptr;
  HocSinh hocSinh;
  treetype T;
  int i,j,k;
  char str[Max],str1[Max];;
  char s[2]="\t";
  char *token;
  MakeNullTree(&T);
  fptr=fopen("thungiem.txt","r");
  /*
 while(scanf(fptr,"%[\t]s",hocSinh.Name)!=EOF)
    {
      printf("%s %ld\n",hocSinh.Name,strlen(hocSinh.Name));
      fscanf(fptr,"%d\t%d",&hocSinh.a,&hocSinh.b);
      fgets(str,100,fptr);
      InsertNode(hocSinh,&T);
    }
  inorderprint(T);
  */
  //printf("\n.\n");
  while(fscanf(fptr,"%s",str)!=EOF)
    {
      // printf("\n.\n");
      fgets(str1,100,fptr);
      strcat(str,str1);
      // printf("\n.\n");
      str[strlen(str)-1]='\0';
      // printf("\n.\n");
      token=strtok(str,s);
      strcpy(hocSinh.Name,token);
      //printf("%s\n",hocSinh.Name);
      token=strtok(NULL,s);
      hocSinh.a=*token-'0';
      token=strtok(NULL,s);
      hocSinh.b=*token-'0';
      InsertNode(hocSinh,&T);  	
    }
  inorderprint(T);
}
