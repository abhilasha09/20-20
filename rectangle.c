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
	printf("%f\n",d.area);
}
void main()
{
	struct point a[3];
	struct rectangle d;
	int n;
	printf("Enter the number of rectangles you want to find area for:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the coordinates of points of rectangle%d\n",i+1);
		input(a);
		d=get_distances(a);
		get_area(&d);
		printf("The area of rectangle%d:",i+1);
		output(d);
	}
}
