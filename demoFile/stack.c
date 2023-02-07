void Initialize(StackType stack)
{
  top=0;
}

empty(StackType stack)
{
  return top==0;
}

int full(StackType stack)
{
  return top ==Max;
}

void push(Eltype el,StackType stack)
{
  if(full(*stack))
    printf("stack overflow");
  else stack[top++]=el;
}

Eltype pop(StackType stack)
{
  if(empty(stack))
    printf("stack underflow");
  else return stack[--top];
}
