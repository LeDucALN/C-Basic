#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio_ext.h>
#define Max 100

typedef struct DanhBa
{
	char name[1000];
	char tel[1000];
	char email[1000];
}DanhBa_t;

void main()
{
	FILE *fptr, *fptr1;
	fptr = fopen ("DanhBa2.txt", "r");
	int i = 0;
	DanhBa_t p[Max];
	DanhBa_t Khach;
	char str[Max];
	int SoLuong;
	
	while (fscanf(fptr,"%s",Khach.name)!=EOF)
	{
	  fgets(str,100,fptr);
	  strcat(Khach.name,str);
	  Khach.name[strlen(Khach.name)-1]='\0';
	  fgets(Khach.tel,100,fptr);
	  Khach.tel[ strlen(Khach.tel) - 1] = '\0';
	  fgets( Khach.email, 100, fptr);
	  Khach.email[ strlen(Khach.email) - 1] = '\0';
	  p[i]=Khach;
	  i++;
	}
	SoLuong=i;	
	fclose(fptr);
	fptr = fopen("DanhBa2.txt", "w+");
	
	    int j;
		printf("Sua thong tin danh ba cua nguoi thu:");
		scanf( "%d", &j );
		fflush(stdin);
		i = j - 1;
		
		//fseek( fptr, sizeof(p[i - 1]), SEEK_SET);
		
		printf("Sua ten nguoi thu %d (i = %d) thanh:", j, i);
		__fpurge(stdin);
		gets(Khach.name);
		__fpurge(stdin);
		Khach.name[ strlen(Khach.name) ] = '\0';
		
		printf("Sua sdt thanh:");
		gets(Khach.tel);
		__fpurge(stdin);
		Khach.tel[ strlen(Khach.tel) ] = '\0';
		
		printf("Sua email thanh:");
		gets( Khach.email);
		Khach.email[ strlen(Khach.email) ] = '\0';
		p[i]=Khach;
		
	for (i = 0; i < SoLuong; i++)
	{
	  fputs(p[i].name,fptr);
	  fputs("\n",fptr);
	  fputs(p[i].tel,fptr);
	  fputs("\n",fptr);
	  fputs(p[i].email,fptr);
	  fputs("\n",fptr);
	}
	fclose(fptr);
}
