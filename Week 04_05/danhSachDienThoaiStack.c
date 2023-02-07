#include <stdio.h>
#include <string.h>

#define Max 50

typedef struct danhba
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;

typedef address Eltype;

typedef struct StackRec
{
  Eltype storage[Max];
  int top;
}StackType;

//typedef struct StackRec StackType;

void Initialize(StackType *stack)
{
  (*stack).top=0;
}

int empty( StackType stack)
{
  return stack.top == 0;
}

int full(StackType stack)
{
  return stack.top==Max;
}

void push(Eltype el,StackType *stack)
{
  if(full(*stack))
    printf("stack tran");
  else (*stack).storage[(*stack).top++]=el;
}

Eltype pop(StackType *stack)
{
  if(empty(*stack))
    printf("stack khong con de lay");
  else return (*stack).storage[--(*stack).top];
}

StackType daoNguocXau(StackType stack)
{

  Eltype mang[Max];
  int i,k;
  i=0,k=0;
  
 while(!empty(stack))
    {
      mang[i]=pop(&stack);
      i++;k++;
    }
  for(i=0;i<k;i++)
    {
      push(mang[i],&stack);
    }
  return stack;
}
/*
void In(StackType stack)
{
  while(!empty(stack))
    printf("%d",pop(&stack));
}
*/

int main()
{
  FILE *fptr1,*fptr2;
  address temp;
  StackType stack;
  char str[Max];
  int i;
  Initialize(&stack);
  fptr1=fopen("text1.txt","r");
  fptr2=fopen("text2.txt","w");
  while(!feof(fptr1))
    {
      fgets(str,100,fptr1);
      fgets(temp.name,100,fptr1);
      fgets(temp.tel,100,fptr1);
      fgets(temp.mail,100,fptr1);
      push(temp,&stack);
      printf("%s\n%s\n%s\n",temp.name,temp.tel,temp.mail);
    }
  //fseek(fptr1,4,SEEK_SET);
  i=1;
  while(!empty(stack))
    {
      temp=pop(&stack);
      fprintf(fptr2,"%d.\n",i);
      fputs(temp.name,fptr2);
      fputs(temp.tel,fptr2);
      fputs(temp.mail,fptr2);
      i++;
    }
  fclose(fptr1);
  fclose(fptr2);
  
}
