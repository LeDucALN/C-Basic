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

void VietVaoFileMoi(FILE *fptr2, treetype tree,treetype *T)
 {
   if(tree!=NULL)
     {
       fprintf(fptr2,"%s %s\n",tree->element.Anh,tree->element.Viet);
       VietVaoFileMoi(fptr2,tree->left,T);
       VietVaoFileMoi(fptr2,tree->right,T);
     }
 }



int menuVaLuaChon(int a,int b)
{
  int luaChon,buff;
  char c;
  printf("+-----+--------------------------------------------------+\n");
  printf("|%25s%6s%25s|\n","","MENU","");
  printf("+-----+--------------------------------------------------+\n");
  printf("|%5d|%-50s|\n",1,"Nap tu dien");
  printf("|%5d|%-50s|\n",2,"Noi dung tu dien");
  printf("|%5d|%-50s|\n",3,"Them/sua tu");
  printf("|%5d|%-50s|\n",4,"Dich cau Anh Viet");
  printf("|%5d|%-50s|\n",5,"Luu file tu dien");
  printf("|%5d|%-50s|\n",6,"Thoat");
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
  char s[Max][Max];
  thoat=0;
  int n;
  FILE *fptr;
  Word tu;
  treetype T,diaChi;
  int i,j,k,t,h;
  char str[Max];
  char str2[Max];
  char str3[Max];
  char yn;
  MakeNullTree(&T);
  do
    {
      luaChon= menuVaLuaChon(1,6);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  fptr=fopen("dict.txt","r");
	  while(fscanf(fptr,"%s %s",tu.Anh,tu.Viet)!=EOF)
	    {
	      fgets(str3,100,fptr);
	      __fpurge(stdin);
	      printf("%s %s\n",tu.Anh,tu.Viet);
	      InsertNode(tu,&T);
	    }
	    break;
	case 2:
	  //ham2
	  inorderprint(T);
	  break;
	case 3:
	  //ham3
	  printf("Nhap vao 1 tu tieng Anh:");
	  __fpurge(stdin);
	  scanf("%s",str);
	  __fpurge(stdin);
	  if(Search(str,T)!=NULL)
	    {
	      printf("Tu da co trong danh sach\n");
	      printf("Ban muon nhap noi dung moi cho tu khong?(y/n):");
	     __fpurge(stdin);
	     scanf("%c",&yn);
	     __fpurge(stdin);
	     if(yn=='y')
	       {
		 printf("Noi dung cap nhap la:");
	     	  __fpurge(stdin);
		  scanf("%s",str2);
		  __fpurge(stdin);
		  strcpy(Search(str,T)->element.Viet,str2);
	       }
	    }
	  else
	    {
	      printf("Giai nghia:");
	      __fpurge(stdin);
	      scanf("%s",str2);
	      __fpurge(stdin);
	      strcpy(tu.Anh,str);
	      strcpy(tu.Viet,str2);
	      InsertNode(tu,&T);
	    }
	  break;
	case 4:
	  //ham4
	  j=0;t=0;
	  printf("Nhap vao cau:");
	  gets(str);
	  __fpurge(stdin);
	  //printf("%s\n",str);
	  str[strlen(str)]='\0';
	  __fpurge(stdin);
	  for(i=0;i<strlen(str)+1;i++)
	    {
	      if(str[i]>='A'&&str[i]<='Z')
		str[i]=str[i]-'A'+'a';
	    if(str[i]==' '||str[i]=='\0')
	      {
		for(k=j;k<i;k++)
		  str2[k-j]=str[k];
		str2[i-j]='\0';
		j=i+1;
		strcpy(s[t],str2);
	       	printf("%s\n",s[t]);
		t++;
	      }
	    }
	  printf("\nDich:");
	  for(j=0;j<t;j++)
	    {
	      diaChi=Search(s[j],T);
	      if(diaChi==NULL)
		printf("<thieu tu> ");
	      else
		printf("%s ",diaChi->element.Viet);
	    }
	  printf("\n");
	  break;
	case 5:
	  //ham5
	  fclose(fptr);
	  fptr=fopen("dict.txt","w+");
	  VietVaoFileMoi(fptr,T,&T);
	  printf("Da viet vao thanh cong\n");
	  break;
	case 6:
	  thoat=1;
	  freetree(T);
	  break;
	}	
    }while(thoat!=1);
  fclose(fptr);
}
