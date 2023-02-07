#include <stdio.h>
#include <math.h>

void ham(double so)
{
  int nguyen;
  double thapPhan;
  nguyen =(int)so;
  thapPhan=so-(double)nguyen;
  printf("Phan nguyen la %d\n",nguyen);
  printf("Phan thap phan la %f\n",thapPhan);
}

int main()
{
  float f;
  printf("Nhap vao so thap phan f:");
  scanf("%f",&f);
  ham(f);
}
