#include <stdio.h>
#include <stdlib.h>

typedef int elmType;
typedef struct nodeType
{
  elmType element;
  struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

void MakeNullTree (treetype *T);
int EmptyTree(treetype T);
treetype LeftChild(treetype n);
treetype RightChild(treetype n);
node_Type *creat_node(elmType NewData);
int IsLeaf(treetype n);
int nb_nodes(treetype T);
treetype creatfrom2( elmType v, treetype l,treetype r);
treetype Add_Left(treetype *Tree, elmType NewData);
treetype Add_Right(treetype *Tree, elmType NewData);
int soLa(treetype Tree);
elmType  max( elmType a, elmType b);
int chieuCao(treetype Tree);
