#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int dai,rong;
  dai=atoi(argv[1]);
  rong=atoi(argv[2]);
  printf("Dien tich la %d\nChu vi la %d\n",dai*rong,2*(dai+rong));
}
