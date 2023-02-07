#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdio_ext.h>

int main(){
  char s[20], f[20];
  StackType stack;
  Initialize(stack);
  int i, j;
  char c;
  j = 0;
  printf("Nhap ky phap: ");
  gets(s);
  __fpurge(stdin);
  for(i = 0; i < strlen(s); i++){
    if(s[i] >= '0' && s[i] <= '9'){
      f[j] = s[i];
      j++;
    }
    if(s[i] == '(') push(s[i],stack);
    if(s[i] == ')') {
      while(stack[top-1] != '('){
	c = pop(stack);
	f[j] = c;
	j++;
      }
      c = pop(stack);
    }
    if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
      if(empty(stack) || stack[top-1] == '(' ||  ((s[i] == '*' || s[i] == '/') && (stack[top-1] == '+' || stack[top-1] == '-'))){
	push(s[i],stack);
      }
      else{
	while((s[i] == '+' || s[i] == '-') && (stack[top-1] == '*' || stack[top-1] == '/') ||
	      (s[i] == '+' || s[i] == '-') && (stack[top-1] == '+' || stack[top-1] == '-') ||
	      (s[i] == '*' || s[i] == '/') && (stack[top-1] == '*' || stack[top-1] == '/')){
        c = pop(stack);
	f[j] = c;
	j++;
	}
	push(s[i],stack);
      }
    }
    if(i == strlen(s) - 1 && empty(stack) == 0){
      while(empty(stack) == 0){
	c = pop(stack);
	f[j] = c;
	j++;
      }
    }
  }
  f[j] = '\0';
  printf("%s \n", f);
  return 0;
}
