#include <stdio.h>

int binSearch(int List[],int Target,int Size)
{
  int Mid, Lo=0,Hi=Size-1;
  while(Lo<=Hi)
    {
      Mid=(Lo+Hi)/2;
      if(List[Mid]==Target)
	return Mid;
      else if(Target<List[Mid])
	Hi=Mid-1;
      else Lo=Mid+1;
    }
  return -1;
}

int main()
{}
