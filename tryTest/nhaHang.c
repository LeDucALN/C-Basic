#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct khachHang
{
  char ID[6];
  char Name[21];
  int Money;
  int DienTu;
  int ThoiTrang;
}KhachHang;

typedef KhachHang elmType;
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

treetype Search(char* x,treetype Root)
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
      diaChi->element.Money=diaChi->element.Money+x.Money;
      if(x.DienTu!=0)
	diaChi->element.DienTu++;
      if(x.ThoiTrang!=0)
	diaChi->element.ThoiTrang++;	
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
      else if(strcmp(x.ID,(*Root)->element.ID)<0) InsertNode(x,&(*Root)->left);
      else if(strcmp(x.ID,(*Root)->element.ID)>0) InsertNode(x,&(*Root)->right);
    }
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
      printf("%-15s%-20s%-15d%-5d%-5d\n",tree->element.ID,tree->element.Name,tree->element.Money,tree->element.DienTu,tree->element.ThoiTrang);
      inorderprint(tree->right);
    }
}

int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Load data");
  printf("|%5d|%-50s|\n",2,"Show data");
  printf("|%5d|%-50s|\n",3,"Add transaction");
  printf("|%5d|%-50s|\n",4,"Thoat");
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
  int thoat,luaChon;
  thoat=0;
  int n;
  int i,j;
  KhachHang s;
  treetype T,diaChi;
  FILE *fptr;
  char str[100];
  int a,b;
  fptr=fopen("giaodich.txt","r");
  MakeNullTree(&T);
  do
    {
      luaChon= menuVaLuaChon(1,4);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  while(fscanf(fptr,"%s%s%10d%10d",s.ID,s.Name,&a,&b)!=EOF)
	    {
	      /*
	      __fpurge(stdin);
	      fgets(s.ID,10,fptr);
	      printf("\nID:%s\n",s.ID);
	      __fpurge(stdin);
	      fgets(s.Name,20,fptr);
	      printf("\nNAME:%s\n",s.Name);
	      __fpurge(stdin);
	      fscanf(fptr,"%10d%10d",&a,&b);
	      __fpurge(stdin);
	      fgets(str,100,fptr);
	      __fpurge(stdin);
	      printf("%d\n%d\n",a,b);
	       printf("%-15s%-20s%-15d%-15d%p\n",s.ID,s.Name,a,b,Search(s.ID,T));
	      */
	      // fscanf(fptr,"%s%s%10d%10d",s.ID,s.Name,&a,&b);
	      fgets(str,100,fptr);
	      //printf("\nID:%s\n",s.ID);;
	      // printf("\nNAME:%s\n",s.Name);
	      //printf("%d\n%d\n",a,b);
	      // printf("%s\n",s.Name);
	      // s.ID[5]='\0';
	      s.Money=a+b;
	      s.DienTu=0;
	      s.ThoiTrang=0;
	      if(a!=0) s.DienTu++;
	      if(b!=0) s.ThoiTrang++;
	      InsertNode(s,&T);
	      // printf("%s%s%-15d%-15d%p\n",s.ID,s.Name,a,b,Search(s.ID,T));
	       printf("%-15s%-20s%-15d%-15d%p\n",s.ID,s.Name,a,b,Search(s.ID,T));
	    }
	    break;
	case 2:
	  //ham2
	  inorderprint(T);
	  break;
	case 3:
	  //ham3
	  s.Money=0;
	  s.DienTu=0;
	  s.ThoiTrang=0;
	  printf("Nhap ID:");
	  __fpurge(stdin);
	  gets(s.ID);
	  __fpurge(stdin);
	  printf("Nhap ten:");
	  __fpurge(stdin);
	  gets(s.Name);
	  __fpurge(stdin);
	  printf("Nhap so tien mua mat hang dien tu:");
	  scanf("%d",&a);
	  printf("Nhap so tien mua mat hang thoi trang:");
	  scanf("%d",&b);
	  s.Money=a+b;
	  if(a!=0) s.DienTu++;
	  if(b!=0) s.ThoiTrang++;
	  InsertNode(s,&T);
	  printf("Cap Nhat Thanh Cong\n");
	  break;
	case 4:
	  thoat=1;
	  freetree(T);
	  break;
	}	
    }while(thoat!=1);
}
