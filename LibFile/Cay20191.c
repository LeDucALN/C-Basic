#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "Cay20191.h"


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

treetype Search( char *x,treetype Root)
{
  if(Root==NULL) return NULL;
  else if(strcmp(Root->element.Anh,x)==0)
    return Root;
  else if(strcmp(Root->element.Anh,x)<0)
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
  else if(strcmp(x.Anh,(*Root)->element.Anh)<0) InsertNode(x,&(*Root)->left);
  else if(strcmp(x.Anh,(*Root)->element.Anh)>0) InsertNode(x,&(*Root)->right);
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

//thu tu giua
void inorderprint( treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      printf("%s %s\n",tree->element.Anh,tree->element.Viet);
      inorderprint(tree->right);
    }
}
