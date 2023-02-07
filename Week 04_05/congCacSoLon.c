#include <stdio.h>
#include <string.h>

#define Max 50
typedef int Eltype;
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

void In(StackType stack)
{
  while(!empty(stack))
    printf("%d",pop(&stack));
}

int main()
{
  StackType stack1,stack2,stack3;
  int i,d;
  int n1,n2,n3,nho;
  char a[Max],b[Max];
  Initialize(&stack1);
  Initialize(&stack2);
  Initialize(&stack3);
  
  printf("Nhap so dau tien:");
  scanf("%s",a);
  a[strlen(a)]='\0';
  printf("Nhap so thu 2:");
  scanf("%s",b);
   b[strlen(b)]='\0';
  //printf("%ld\n",strlen(b));
  for(i=0;i<strlen(a);i++)
    push(a[i]-'0',&stack1);
  for(i=0;i<strlen(b);i++)
    push(b[i]-'0',&stack2);

  nho=0;n3=0;
  while(!empty(stack1)||!empty(stack2))
    {
      if(!empty(stack1)) n1=pop(&stack1);
      else n1=0;
      if(!empty(stack2)) n2=pop(&stack2);
      else n2=0;
      n3=n1+n2+nho;
      if(n3>=10)
	{
	  nho=1;
	  n3=n3-10;
	}
      else nho=0;
      push(n3,&stack3);
    }
  // In(stack3);
  // stack3=daoNguocXau(stack3);
  In(stack3);
  printf("\n");
  
}
