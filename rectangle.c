#include<stdio.h>
#include<math.h>
struct point
{
	float x,y;
};
struct rectangle
{
	struct point p[3];
	float l,b,area;
};
struct rectangles
{
	int n;
	struct rectangle r[100];
};	
struct rectangle input(struct rectangle r)
{
	for(int i=0;i<3;i++)
	{
		printf("Enter x%d",i+1);
		scanf("%f",&r.p[i].x);
		printf("Enter y%d",i+1);
		scanf("%f",&r.p[i].y);
	}
return r;
}

	

struct rectangle get_distances(struct rectangle d)
{
	float d1,d2,d3;
	d1=sqrt(pow((d.p[1].y-d.p[0].y),2)+pow((d.p[1].x-d.p[0].x),2));
	d2=sqrt(pow((d.p[2].y-d.p[1].y),2)+pow((d.p[2].x-d.p[1].x),2));
	d3=sqrt(pow((d.p[2].y-d.p[0].y),2)+pow((d.p[2].x-d.p[0].x),2));
	if((d1>d2)&&(d1>d3))
	{
		d.l=d2;
		d.b=d3;
	}
	if((d2>d1)&&(d2>d3))
	{
		d.l=d1;
		d.b=d3;	
	}
	if((d3>d1)&&(d3>d2))
	{
		d.l=d1;
		d.b=d2;
	}
	return d;
	
}

struct rectangle get_area(struct rectangle d)
{
	d.area=(d.l)*(d.b);
	return d;
}
void output(struct rectangle d)
{
	printf("%f\n",d.area);
}
void main()
{
	
	struct rectangle d;
	
	int n;
	printf("Enter the n");
	scanf("%d",&n);
	d=input(d);
	d=get_distances(d);
	printf("%f",d.l);
	printf("%f",d.b);
	d=get_area(d);
	printf("The area of rectangle:");
	output(d);
	
}
