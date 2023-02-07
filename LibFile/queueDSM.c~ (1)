#include<stdio.h>
#include<stdlib.h>

typedef struct node {
 int data;
 struct node *link;
}node;

node *push( node *p, int value) {
 node *temp;
temp=( node *)malloc(sizeof(node));
if(temp==NULL) {
printf("No Memory available Error\n");
exit(0);
 }
temp->data = value;
temp->link = p;
p = temp;
return(p);
}

node *pop( node *p, int*value)
{
  node *temp;
 if(p==NULL){
 printf(" The stack is empty cannot pop Error\n");
 exit(0);
  }
 *value = p->data;
 temp = p;
 p = p->link;
 free(temp);
return(p);
 }
 int main(){
   int n,i,a;
   node  *top = NULL;
  printf("Nhap vao so phan tu : ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
     scanf("%d",&a);
     top=push(top,a);
       }
   printf("Day so sau khi FILO la: ");
   while(top!=NULL){
     top=pop(top,&a);
     printf("%d ",a);
     }
   printf("\n");
   return 0;
 }
