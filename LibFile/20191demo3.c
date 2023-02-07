#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "Cay20191.h"

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
  printf("|%5d|%-50s|\n",5,"Thoat");
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
  char yn;
  MakeNullTree(&T);
  do
    {
      luaChon= menuVaLuaChon(1,5);
      switch(luaChon)
	{
	case 1:
	  //ham1
	  fptr=fopen("dict.txt","r");
	  while(!feof(fptr))
	    {
	      fscanf(fptr,"%s %s",tu.Anh,tu.Viet);
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
	  printf("%s %ld\n",str,strlen(str));
	  str[strlen(str)]='\0';
	  __fpurge(stdin);
	  for(i=0;i<strlen(str)+1;i++)
	    if(str[i]==' '||str[i]=='\0')
	      {
		for(k=j;k<i;k++)
		  str2[k-j]=str[k];
		str2[i-j]='\0';
		j=i+1;
		strcpy(s[t],str2);
		printf("%s %ld\n",s[t],strlen(s[t]));
		t++;
	      }
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
	  thoat=1;
	  break;
	}	
    }while(thoat!=1);
}
