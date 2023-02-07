#include<stdio.h>
#include<stdlib.h>

typedef int elementType;
typedef struct node{
  elementType data;
  struct node *next;
}node;

node *EnQueue(node *top, elementType value){
  node *new; node *chay;
  new=(node*)malloc(sizeof(node));
    new->data=value;
    new->next=NULL;
    if(top==NULL)
      top=new;
    else{
    chay=top;
  while(chay->next!=NULL)
    chay=chay->next;
   chay->next=new;
    }
  return top;
}

node *DeQueue( node *p, elementType *value)
{
 node *temp;
 if(p==NULL){
 printf(" The queue is empty cannot pop Error\n");
 exit(0);
 }
 *value = p->data;
 temp = p;
 p = p->next;
 free(temp);
return p;
}
 int main(){
   int n,i,a;
   node  *top = NULL;
  printf("Nhap vao so phan tu : ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
     scanf("%d",&a);
     top=EnQueue(top,a);
       }
   printf("Day so sau khi FIFO la: ");
   while(top!=NULL){
     top=DeQueue(top,&a);
     printf("%d ",a);
     }
   printf("\n");
   return 0;
 }
