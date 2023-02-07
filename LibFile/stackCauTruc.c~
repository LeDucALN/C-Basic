#include <stdio.h>
#include <string.h>
#include "stackCauTruc.h"
#define Max 50

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

