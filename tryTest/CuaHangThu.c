#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define Max 100

typedef struct
{
  char Name[Max];
  int Gia;
  int SoLuong;
}SanPham;

typedef SanPham elmType;

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

void DeleteNode(elmType x,treetype *Root)
{
  if(*Root!=NULL)
    if(strcmp(x.Name,(*Root)->element.Name)<0) DeleteNode(x,&(*Root)->left);
    else if(strcmp(x.Name,(*Root)->element.Name)>0)
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
      printf("%-10s%-10d%-5d\n",tree->element.Name,tree->element.Gia,tree->element.SoLuong);
      inorderprint(tree->right);
    }
}


void InsertNodeTheoGia( elmType x, treetype *Root)
{
  if(*Root==NULL)
    {
      *Root=(node_Type*)malloc(sizeof(node_Type));
      (*Root)->element=x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if(x.Gia<(*Root)->element.Gia) InsertNode(x,&(*Root)->left);
  else if(x.Gia>(*Root)->element.Gia) InsertNode(x,&(*Root)->right);
}

void SaoChepCayMoiTheoGia(treetype T1,treetype *T2)
{
  if(T1!=NULL)
    {
      SaoChepCayMoiTheoGia(T1->left,T2);
      InsertNodeTheoGia(T1->element,T2);
      SaoChepCayMoiTheoGia(T1->right,T2);
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

void VietVaoFileMoi(FILE *fptr2, treetype tree,treetype *T)
 {
   if(tree!=NULL)
     {
       VietVaoFileMoi(fptr2,tree->left,T);
       fprintf(fptr2,"%s\t%d\t%d\n",tree->element.Name,tree->element.Gia,tree->element.SoLuong);
       VietVaoFileMoi(fptr2,tree->right,T);
     }
 }


//1,in menu va nhap lua chon
int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Nhap so lieu vao cay");
  printf("|%5d|%-50s|\n",2,"In ra cay theo thu tu tu dien cua ten");
  printf("|%5d|%-50s|\n",3,"In ra cay theo thu tu tang cua gia");
  printf("|%5d|%-50s|\n",4,"Ban hang");
  printf("|%5d|%-50s|\n",5,"Viet lai vao file va thoat");
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
  int i,j,k;
  int n;
  treetype T,T2;
  treetype diaChi;
  SanPham sanPham;
  char str[Max];
  FILE *fptr;
  int thoat,luaChon;
  int soLuong;
  thoat=0;
  fptr=fopen("cuahangthu.txt","r");
  MakeNullTree(&T);
  MakeNullTree(&T2);
  do
    {
      luaChon= menuVaLuaChon(1,5);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  fscanf(fptr,"%d",&n);
	  fgets(str,100,fptr);
	  for(i=0;i<n;i++)
	    {
	      fscanf(fptr,"%s\t%d\t%d",sanPham.Name,&sanPham.Gia,&sanPham.SoLuong);
	      fgets(str,100,fptr);
	      InsertNode(sanPham,&T);
	    }
	    break;
	case 2:
	  //ham2
	  inorderprint(T);
	  break;
	case 3:
	  //ham3
	  SaoChepCayMoiTheoGia(T,&T2);
	  inorderprint(T2);
	  break;
	case 4:
	  //ham4
	  printf("Nhap mat hang ban muon mua:");
	  __fpurge(stdin);
	  gets(str);
	  __fpurge(stdin);
	  diaChi=Search(str,T);
	  if(diaChi==NULL)
	    printf("Khong co mat hang nay\n");
	  else
	    {
	      if(diaChi->element.SoLuong==0)
		printf("Da het hang\n");
	      else
		{
		  printf("San pham nay co gia %d va co so luong %d\n",diaChi->element.Gia,diaChi->element.SoLuong);
		  while(1)
		    {
		      printf("Nhap so luong ban muon mua:");
		      scanf("%d",&soLuong);
		      __fpurge(stdin);
		      if(soLuong>diaChi->element.SoLuong)
			printf("Khong co du mat hang\n");
		      else
			if(soLuong<0)
			  printf("Nhap sai cu phap\n");
			else
			  {
			    printf("Mua thanh cong\n");
			    diaChi->element.SoLuong=diaChi->element.SoLuong - soLuong;
			    break;
			  }
		    }
		}
	    }
	  break;
	case 5:
	  thoat=1;
	  fclose(fptr);
	  fptr=fopen("cuahangthu.txt","w+");
	  VietVaoFileMoi(fptr,T,&T);
	  break;
	}
    }while(thoat!=1);
}
 

