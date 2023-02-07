#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define Max 25
#define MaxLength 100

typedef struct
{
  char Anh[Max];
  char Viet[Max];
}Word;


typedef Word elmType;
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
treetype Search( char *x,treetype Root);
void InsertNode( elmType x, treetype *Root);
void freetree(treetype Tree);
void inorderprint( treetype tree);
