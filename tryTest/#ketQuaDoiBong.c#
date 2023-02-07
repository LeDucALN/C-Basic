#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define Max 10

typedef struct
{
  char ID[Max];
  int diem;
}doiBong;

typedef doiBong elmType;
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
/*
int soLa(treetype Tree)
{
  if(Tree==NULL) return 0;
  else
    if(IsLeaf(Tree)==1) return 1;
    else
      return soLa(LeftChild(Tree))+soLa(RightChild(Tree));
}

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
  else if(strcmp(Root->element.ID,x)==0)
    return Root;
  else if(strcmp(Root->element.ID,x)<0)
    return Search(x,RightChild(Root));
  else
    return Search(x,LeftChild(Root));
}

void InsertNode( elmType x, treetype *Root)
{
  treetype diaChi;
  if(Search(x.ID,*Root)!=NULL)
    {
      diaChi=Search(x.ID,*Root);
      diaChi->element.diem=diaChi->element.diem + x.diem;
    }
  else
    {
      if(*Root==NULL)
	{
	  *Root=(node_Type*)malloc(sizeof(node_Type));
	  (*Root)->element=x;
	  (*Root)->left=NULL;
	  (*Root)->right=NULL;
	}
       else if(strcmp((*Root)->element.ID,x.ID)>0) InsertNode(x,&(*Root)->left);
       else if(strcmp((*Root)->element.ID,x.ID)<0) InsertNode(x,&(*Root)->right);
      // printf("Nut thu:%d\n",nb_nodes(*Root));
      //printf("Dia chi:%p\n",Search(x.ID,*Root));
    }
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

void DeleteNode(elmType x,treetype *Root)
{
  if(*Root!=NULL)
    if(strcmp((*Root)->element.ID,x.ID)>0) DeleteNode(x,&(*Root)->left);
    else if(strcmp((*Root)->element.ID,x.ID)<0)
      DeleteNode(x,&(*Root)->right);
    else if(((*Root)->left==NULL)&&((*Root)->right==NULL))
      *Root=NULL;
    else if((*Root)->left==NULL)
      *Root=(*Root)->right;
    else if((*Root)->right==NULL)
      *Root=(*Root)->left;
    else (*Root)->element=DeleteMin(&(*Root)->right);
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
      printf("%s\t%d\n",tree->element.ID,tree->element.diem);
      inorderprint(tree->right);
    }
}

void XoaDiemDuoiX(int X,treetype tree,treetype *T)
 {
   if(tree!=NULL)
     {
       XoaDiemDuoiX(X,tree->left,T);
       if(tree->element.diem<X)
	 DeleteNode(tree->element,T);
       XoaDiemDuoiX(X,tree->right,T);
     }
 }

void VietVaoFileMoi(FILE *fptr2, treetype tree,treetype *T)
 {
   if(tree!=NULL)
     {
       VietVaoFileMoi(fptr2,tree->left,T);
       fprintf(fptr2,"%s\t%d\n",tree->element.ID,tree->element.diem);
       VietVaoFileMoi(fptr2,tree->right,T);
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
   
//1,in menu va nhap lua chon
int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Tao cay");
  printf("|%5d|%-50s|\n",2,"Ket qua");
  printf("|%5d|%-50s|\n",3,"Tim kiem");
  printf("|%5d|%-50s|\n",4,"Xuong hang");
  printf("|%5d|%-50s|\n",5,"Xuat file");
  printf("+-----+--------------------------------------------------+\n");

  do
    {
      __fpurge(stdin);
      printf("Nhap vao lua chon cua ban:");
      buff=scanf("%d%c",&luaChon,&c);
      if(buff!=2&&c!='\n'||luaChon<a||luaChon>b) printf("Ban da nhap sai cu phap\n");
    }while(buff!=2&&c!='\n'||luaChon<a||luaChon>b);
  return luaChon;
}

int main()
{
  int i,j;
  int X;
  int diem1,diem2,diem;
  elmType doiBong1,doiBong2;
  char str1[Max],str2[Max],str[Max];
  treetype T,diaChi;
  int thoat,luaChon;
  thoat=0;
  FILE *fptr1,*fptr2;
  fptr1=fopen("BongDa.txt","r");
  fptr2=fopen("KetQua.txt","w+");
  MakeNullTree(&T);
  do
    {
      luaChon= menuVaLuaChon(1,5);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  while(fscanf(fptr1,"%s\t%s\t%d\t%d",str1,str2,&diem1,&diem2)!=EOF)
	    {
	      fgets(str,100,fptr1);
	      doiBong1.diem=0;doiBong2.diem=0;
	      strcpy(doiBong1.ID,str1);
	      strcpy(doiBong2.ID,str2);
	      // printf("doiBong1:%s %d\n",doiBong1.ID,diem1);     
	      //printf("doiBong2:%s %d\n",doiBong2.ID,diem2);
	      if(diem1>diem2) doiBong1.diem=doiBong1.diem+3;
	      else if(diem1<diem2) doiBong2.diem=doiBong2.diem+3;
	      else
		{
		  doiBong1.diem=doiBong1.diem+1;
		  doiBong2.diem=doiBong2.diem+1;
		}
	      // printf("doiBong1:%s %d\n",doiBong1.ID,doiBong1.diem);
	      // printf("doiBong2:%s %d\n",doiBong2.ID,doiBong2.diem);
	      
	      InsertNode(doiBong1,&T);
	      InsertNode(doiBong2,&T);
	    }
	    break;
	case 2:
	  //ham2
	  inorderprint(T);
	  printf("\n");
	  break;
	case 3:
	  //ham3
	  printf("Nhap vao ten ma doi bong can tim:");
	  __fpurge(stdin);
	  gets(str);
	  __fpurge(stdin);
	  diaChi=Search(str,T);
	  if(diaChi==NULL)
	    printf("Khong co doi bong nay\n");
	  else
	    printf("Diem cua doi bong nay la:%d",diaChi->element.diem);
	  printf("\n");
	  break;
	case 4:
	  //ham4
	  printf("Nhap vao so nguyen X:");
	  scanf("%d",&X);
	  XoaDiemDuoiX(X,T,&T);
	  inorderprint(T);
	  break;
	case 5:
	  VietVaoFileMoi(fptr2,T,&T);
	  thoat=1; 
	  break;
	}	
    }while(thoat!=1);
  fclose(fptr2);
  fclose(fptr1);
}
