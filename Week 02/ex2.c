#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
double x;
double y;
} point_t;

typedef struct circle
{
point_t center;
double radius;
} circle_t;

int is_in_circle(point_t p, circle_t c)
{
  double d;
  d=sqrt((p.x-(c.center).x)*(p.x-(c.center).x)+(p.y-(c.center).y)*(p.y-(c.center).y));
  if(d>c.radius) return 0;
  return 1;
}

int main()
{
  point_t p;
  circle_t c;
  printf("Nhap cac thong so cua p:");
  scanf("%lf %lf",&p.x,&p.y);
  printf("Nhap cac thong so cua center c:");
  scanf("%lf %lf",&(c.center).x,&(c.center).y);
  printf("Nhap vao r:");
  scanf("%lf",&c.radius);
  if(is_in_circle(p,c)==0) printf("Nam ngoai\n");
  else printf("Nam trong\n");
}
