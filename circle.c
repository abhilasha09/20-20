#include<stdio.h>
#include<math.h>
struct point
{
double x,y;
};
struct circle
{
double radius;
struct point c;
};
void input(struct circle ci[2])
{
for(int i=0;i<2;i++)
{
printf("Enter the radius of circle%d\n",i+1);
scanf("%lf",&ci[i].radius);
printf("Enter coordinates of center (x,y)\n");
scanf("%lf",&ci[i].c.x);
scanf("%lf",&ci[i].c.y);
}
}
void calculate(struct circle ci[2],double *d,double *d1,double *d2)
{
double d;
d=sqrt(pow((ci[1].c.y-ci[0].c.y),2)+pow((ci[1].c.x-ci[0].c.x),2));
double r1,r2,d1,d2;
r1=ci[0].radius;
r2=ci[1].radius;
d1=r1+r2;
d2=fabs((r1-r2));
}
void output(double d,double d1,double d2)
{
if((d==d1)||(d==d2)||((d<d1)&&(d>d2)))
printf("The circle are intersecting");
else
printf("The circles do not intersect");
}
void main()
{
struct circle ci[2];
for(int i=0;i<2;i++)
{
printf("Enter the radius of circle%d\n",i+1);
scanf("%lf",&ci[i].radius);
printf("Enter coordinates of center (x,y)\n");
scanf("%lf",&ci[i].c.x);
scanf("%lf",&ci[i].c.y);
}
double d;
d=sqrt(pow((ci[1].c.y-ci[0].c.y),2)+pow((ci[1].c.x-ci[0].c.x),2));
double r1,r2,d1,d2;
r1=ci[0].radius;
r2=ci[1].radius;
d1=r1+r2;
d2=fabs((r1-r2));
if((d==d1)||(d==d2)||((d<d1)&&(d>d2)))
printf("The circle are intersecting");
else
printf("The circles do not intersect");
}
