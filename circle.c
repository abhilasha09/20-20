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
struct circles
{
	struct circle ci[2];
	double d,d1,d2;
};
void instance(int *n)
{
	printf("enter no.of.instances");
	scanf("%d",n);
}
void input(int n,struct circles cir[n])
{
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<2;i++)
		{
			printf("Enter the radius of circle%d\n",i+1);
			scanf("%lf",&cir[j].ci[i].radius);
			printf("Enter coordinates of center (x,y)\n");
			scanf("%lf",&cir[j].ci[i].c.x);
			scanf("%lf",&cir[j].ci[i].c.y);
		}
	}
}
void calculate(int n,struct circles cir[n])
{
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<2;i++)
		{
			cir[j].d=sqrt(pow((cir[j].ci[1].c.y-cir[j].ci[0].c.y),2)+pow((cir[j].ci[1].c.x-cir[j].ci[0].c.x),2));
			double r1,r2;
			r1=cir[j].ci[0].radius;
			r2=cir[j].ci[1].radius;
			cir[j].d1=r1+r2;
			cir[j].d2=fabs((r1-r2));
		}
	}
}
void output(int n,struct circles cir[n])
{
	for(int j=0;j<n;j++)
	{
			double d,d1,d2;
			d=cir[j].d;
			d1=cir[j].d1;
			d2=cir[j].d2;
			if((d==d1)||(d==d2)||((d<d1)&&(d>d2)))
			printf("The circle are intersecting\n");
			else
			printf("The circles do not intersect\n");
	}
}
void main()
{
	int n;
	instance(&n);
	struct circles cir[n];
	input(n,cir);
	calculate(n,cir);
	output(n,cir);
}
