#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#define Max 100
#define MaxDanhBa 100
#define SoLuong 10

typedef struct DanhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;


typedef address elmType;

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

treetype SearchEmail(char *str,treetype Root)
{
  if(Root==NULL) return NULL;
  else if(strcmp((Root->element).mail,str)==0)
    return Root;
  else if(strcmp((Root->element).mail,str)<0)
    return SearchEmail(str,RightChild(Root));
  else
    return SearchEmail(str,LeftChild(Root));
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
  else if(strcmp(x.mail,((*Root)->element).mail)<0) InsertNode(x,&(*Root)->left);
  else if(strcmp(x.mail,((*Root)->element).mail)>0) InsertNode(x,&(*Root)->right);
}

void inorderprint( treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      
      printf("Ten:%s\n",(tree->element).name);
      printf("So dien thoai:%s\n",(tree->element).tel);
      printf("Email:%s\n\n",(tree->element).mail);
      
      inorderprint(tree->right);
    }
}

int main()
{
  elmType danhBa;
  int i,n,m;
  char str[Max],mail[Max];
  treetype T;
  treetype mkr;
  MakeNullTree(&T);
  FILE *fptr;
  fptr=fopen("danhBa.txt","r");
  printf("Cac email:\n\n");
  for(i=0;i<SoLuong;i++)
    {
      fgets(str,100,fptr);
      fgets(danhBa.name,100,fptr);
      danhBa.name[strlen(danhBa.name)-1]='\0';
      fgets(danhBa.tel,100,fptr);
      danhBa.tel[strlen(danhBa.tel)-1]='\0';
      fgets(danhBa.mail,100,fptr);
      danhBa.mail[strlen(danhBa.mail)-1]='\0';
      printf("%s\n",danhBa.mail);
      InsertNode(danhBa,&T);
    }
  printf("Ban muon tim email nao:");
  __fpurge(stdin);
  gets(mail);
  __fpurge(stdin);
  mkr=SearchEmail(mail,T);
  if(mkr==NULL)
    printf("Not found\n");
  else
    {
      printf("Ten:%s\n",(mkr->element).name);
      printf("So dien thoai:%s\n",(mkr->element).tel);
      printf("Email:%s\n",(mkr->element).mail);
    }
  printf("\n");

  printf("+In theo chieu tang cua email:\n\n");
  inorderprint(T);
  fclose(fptr);
}
