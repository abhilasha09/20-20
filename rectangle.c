#include<stdio.h>
#include<math.h>
struct point
{
	float x,y;
};
struct rectangle
{
	float d1,d2,d3,area;
};
void input(struct point a[])
{
	for(int i=0;i<3;i++)
	{
		printf("Enter x%d",i+1);
		scanf("%f",&a[i].x);
		printf("Enter y%d",i+1);
		scanf("%f",&a[i].y);
	}
}
struct rectangle get_distances(struct point a[])
{
	struct rectangle d;
	d.d1=sqrt(pow((a[1].y-a[0].y),2)+pow((a[1].x-a[0].x),2));
	d.d2=sqrt(pow((a[2].y-a[1].y),2)+pow((a[2].x-a[1].x),2));
	d.d3=sqrt(pow((a[2].y-a[0].y),2)+pow((a[2].x-a[0].x),2));
	return d;
}
struct rectangle get_area(struct rectangle *d)
{
	float d1,d2,d3;
	d1=d->d1;
	d2=d->d2;
	d3=d->d3;
	if((d1>d2)&&(d1>d3))
		d->area=d2*d3;
	if((d2>d1)&&(d2>d3))
		d->area=d1*d3;
	if((d3>d1)&&(d3>d2))
		d->area=d1*d2;
}
void output(struct rectangle d)
{
	printf("Area of the rectangle=%f",d.area);
}
void main()
{
	struct point a[3];
	struct rectangle d;
	input(a);
	d=get_distances(a);
	get_area(&d);
	output(d);
}
