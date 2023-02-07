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
  char Username[Max];
  char Password[Max];
  float Diem;
}SinhVien;
typedef SinhVien elmType;
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
  else if(strcmp(Root->element.Username,x)==0)
    return Root;
  else if(strcmp(Root->element.Username,x)<0)
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
  else if(strcmp(x.Username,(*Root)->element.Username)<0) InsertNode(x,&(*Root)->left);
  else if(strcmp(x.Username,(*Root)->element.Username)>0) InsertNode(x,&(*Root)->right);
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
    if(strcmp(x.Username,(*Root)->element.Username)<0) DeleteNode(x,&(*Root)->left);
    else if(strcmp(x.Username,(*Root)->element.Username)>0)
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
      printf("Ten:%s\nMat khau:%s\nDiem:%f\n",tree->element.Username,tree->element.Password,tree->element.Diem);
      inorderprint(tree->right);
    }
}

void inorderprintWithoutAdmin( treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      if(strcmp(tree->element.Username,"Admin")!=0)
	printf("Ten:%s\nMat khau:%s\nDiem:%f\n",tree->element.Username,tree->element.Password,tree->element.Diem);
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

//1,in menu va nhap lua chon
int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Dang nhap");
  printf("|%5d|%-50s|\n",2,"Thoat");
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


int menuVaLuaChonHocSinh(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Xem diem");
  printf("|%5d|%-50s|\n",2,"Thay doi mat khau");
  printf("|%5d|%-50s|\n",3,"Ghi lai thong tin va thoat");
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


int menuVaLuaChonAdmin(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Them 1 sinh vien");
  printf("|%5d|%-50s|\n",2,"In ra danh sach");
  printf("|%5d|%-50s|\n",3,"Xoa sinh vien");
  printf("|%5d|%-50s|\n",4,"Ghi lai thong tin va thoat");
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

void VietVaoFileMoi(FILE *fptr2, treetype tree,treetype *T)
 {
   if(tree!=NULL)
     {
       VietVaoFileMoi(fptr2,tree->left,T);
       fprintf(fptr2,"%s\t%s\t%f\n",tree->element.Username,tree->element.Password,tree->element.Diem);
       VietVaoFileMoi(fptr2,tree->right,T);
     }
 }



int main()
{
  FILE *fptr;
  int thoat,luaChon;
  int luaChonHS,thoatHS,luaChonAdmin,thoatAdmin;
  elmType sinhVien;
  char str[Max];
  char matKhau[Max],ten[Max],matKhauTuongUng[Max],matKhau1[Max],matKhau2[Max];
  treetype T,diaChi;
  int i,j,k;
  int n;
  int demLanSai;
  thoat=0;
  thoatHS=0;thoatAdmin=0;
  MakeNullTree(&T);
  fptr=fopen("sinhvien.txt","r");
  while(fscanf(fptr,"%s\t%s\t%f",sinhVien.Username,sinhVien.Password,&sinhVien.Diem)!=EOF)
    {
      fgets(str,100,fptr);
      InsertNode(sinhVien,&T);
    }
  inorderprint(T);
  do
    {
      luaChon= menuVaLuaChon(1,2);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  demLanSai=0;
	  while(1)
	    {
	      printf("Nhap vao Username:");
	      __fpurge(stdin);
	      gets(ten);
	      // printf("%s %ld\n",ten,strlen(ten));
	      __fpurge(stdin);
	      diaChi=Search(ten,T);
	      if(diaChi==NULL)
		{
		  printf("Khong co ten nay\n");
		  break;
		}
	      else
		{
		  //printf("here\n");
	      strcpy(matKhauTuongUng,diaChi->element.Password);
	      __fpurge(stdin);
	      printf("Nhap vao mat khau:");
	      gets(matKhau);
	      __fpurge(stdin);
	      if(strcmp(matKhau,matKhauTuongUng)==0)
		break;
	      else
		{
		  printf("Ban da nhap sai\n");
		  demLanSai++;
		}
	      if(demLanSai==3) break;
	    }
	    }
	 
	  if(demLanSai==3) break;
	  if(diaChi!=NULL)
	    {
	  if(strcmp(ten,"Admin")!=0)
	    {
	      do
		{
		  luaChonHS=menuVaLuaChonHocSinh(1,3);
		    switch(luaChonHS)
		      {
		      case 1:
		      //ham1
		      printf("Diem cua sinh vien la:%f\n",diaChi->element.Diem);
		      break;
		      case 2:
		      //ham2
		      printf("Nhap mat khau moi:");
		      __fpurge(stdin);
		      gets(matKhau1);
		      __fpurge(stdin);
		      printf("Nhap lai mat khau:");
		      __fpurge(stdin);
		      gets(matKhau2);
		      __fpurge(stdin);
		      if(strcmp(matKhau1,matKhau2)==0)
			strcpy(diaChi->element.Password,matKhau1);
		      else
			{
			  printf("Nhap sai\n");
			}
		      break;
		      case 3:
		      fclose(fptr);
		      fptr=fopen("sinhvien.txt","w+");
		      VietVaoFileMoi(fptr,T,&T);
		      thoatHS=1;
		      break;
		      }
		}while(thoatHS!=1);
	    }
	  else
	    {
	      do
		{
		  luaChonAdmin=menuVaLuaChonAdmin(1,4);
		    switch(luaChonAdmin)
		      {
		      case 1:
		      //ham1
		      printf("Nhap vao Username can them:");
		      __fpurge(stdin);
		      gets(sinhVien.Username);
		      __fpurge(stdin);
		      printf("Nhap vao mat khau tuong ung:");
		      gets(sinhVien.Password);
		      __fpurge(stdin);
		      printf("Nhap vao diem:");
		      scanf("%f",&sinhVien.Diem);
		      InsertNode(sinhVien,&T);
		      break;
		      case 2:
		      //ham2
		      inorderprintWithoutAdmin(T);
		      break;
		      case 3:
		      //ham3
		      while(1)
			{
			  printf("Nhap vao ten sinh vien can xoa:");
			  __fpurge(stdin);
			  gets(ten);
			  __fpurge(stdin);
			  if(strcmp(ten,"Admin")!=0)
			    {
			      diaChi=Search(ten,T);
			      if(diaChi==NULL)
				printf("Khong co ten nay\n");
			      else
				{
			      printf("%s\t%s\t%f\n",diaChi->element.Username,diaChi->element.Password,diaChi->element.Diem);
			      DeleteNode(diaChi->element,&T);
				}
			      break;
			    }
			  else
			    printf("Khong duoc xoa Admin\n");
			}
		      break;
		      case 4:		      
		      fclose(fptr);
		      fptr=fopen("sinhvien.txt","w+");
		      VietVaoFileMoi(fptr,T,&T);
		      thoatAdmin=1;
		      break;
		      }
		}while(thoatAdmin!=1);
	    }
	    }
	    break;
	case 2:
	  thoat=1;
	  break;
	}
      if(demLanSai==3) break;
    }while(thoat!=1);
}
