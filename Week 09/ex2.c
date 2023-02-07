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

void InsertNodeByName(elmType x, treetype *Root)
{
  if(*Root==NULL)
    {
      *Root=(node_Type*)malloc(sizeof(node_Type));
      (*Root)->element=x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if(strcmp(x.name,((*Root)->element).name)<0) InsertNodeByName(x,&(*Root)->left);
  else if(strcmp(x.name,((*Root)->element).name)>0) InsertNodeByName(x,&(*Root)->right);
}


void inorderprint( treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      
      printf("\nTen:%s",(tree->element).name);
      printf("So dien thoai:%s",(tree->element).tel);
      printf("Email:%s\n",(tree->element).mail);
      
      inorderprint(tree->right);
    }
}

treetype duaVaoCayMoiTheoName(treetype tree, treetype NewTree)
{
  if(tree!=NULL)
    {
      InsertNodeByName(tree->element,&NewTree);
      duaVaoCayMoiTheoName(tree->left,NewTree);
      duaVaoCayMoiTheoName(tree->right,NewTree);
    }
  return NewTree;
}

void VietRaFileTheoTen(FILE *fptr,treetype tree)
{
  int i;
  if(tree!=NULL)
    {
      VietRaFileTheoTen(fptr,tree->left);
      fprintf(fptr,"\n");
      fputs((tree->element).name,fptr);
      fputs((tree->element).tel,fptr);
      fputs((tree->element).mail,fptr);      
      VietRaFileTheoTen(fptr,tree->right);
    }
}

int main()
{
  elmType danhBa;
  int i,n,m;
  char str[Max],mail[Max];
  treetype T,NewTree;
  treetype mkr;
  MakeNullTree(&T);
  MakeNullTree(&NewTree);
  FILE *fptr1,*fptr2;
  fptr1=fopen("danhBa.txt","r");
  fptr2=fopen("danhBaTheoTen.txt","w+");
  //printf("Cac email:\n\n");
  for(i=0;i<SoLuong;i++)
    {
      fgets(str,100,fptr1);
      fgets(danhBa.name,100,fptr1);
      //danhBa.name[strlen(danhBa.name)-1]='\0';
      fgets(danhBa.tel,100,fptr1);
      // danhBa.tel[strlen(danhBa.tel)-1]='\0';
      fgets(danhBa.mail,100,fptr1);
      // danhBa.mail[strlen(danhBa.mail)-1]='\0';
      // printf("%s\n",danhBa.mail);
      InsertNode(danhBa,&T);
    }
  NewTree= duaVaoCayMoiTheoName(T,NewTree);
  printf("+In theo chieu tang cua ten:\n\n");
  inorderprint(NewTree);
  VietRaFileTheoTen(fptr2,NewTree);
  fclose(fptr2);
  fclose(fptr1);
}
