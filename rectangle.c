#include<stdio.h>
#include<math.h>
struct coordinate
{
float x,y;
};

void input(struct coordinate a[])
{
	for(int i=0;i<3;i++)
	{
		printf("Enter x%d",i+1);
		scanf("%f",&a[i].x);
		printf("Enter y%d",i+1);
		scanf("%f",&a[i].y);
	}
}
float compute(struct coordinate a[])
{
	float d1,d2,d3,area;
	d1=sqrt(pow((a[1].y-a[0].y),2)+pow((a[1].x-a[0].x),2));
	d2=sqrt(pow((a[2].y-a[1].y),2)+pow((a[2].x-a[1].x),2));
	d3=sqrt(pow((a[2].y-a[0].y),2)+pow((a[2].x-a[0].x),2));
	if((d1>d2)&&(d1>d3))
	area=d2*d3;
	if((d2>d1)&&(d2>d3))
	area=d1*d3;
	if((d3>d1)&&(d3>d2))
	area=d1*d2;
	return area;
}
void output(float area)
{
	printf("Area of the rectangle=%f",area);
}
void main()
{
	struct coordinate a[3];float area;
	input(a);
	area=compute(a);
output(area);
}
