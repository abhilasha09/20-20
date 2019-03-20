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
void get_instance(struct rectangles *r1)
{
    printf("Enter no of rectangles");
    scanf("%d",&r1->n);
}
void input(struct rectangles *r1)
{
	for(int j=0;j<r1->n;j++)
	{
	    for(int i=0;i<3;i++)
	    {
		    printf("Enter x%d",i+1);
		    scanf("%f",&r1->r[j].p[i].x);
		    printf("Enter y%d",i+1);
	    	scanf("%f",&r1->r[j].p[i].y);
	    }
	}
}
void get_distances(struct rectangles *r1)
{
	float d1,d2,d3;
	for(int i=0;i<r1->n;i++)
	{
	d1=sqrt(pow((r1->r[i].p[1].y-r1->r[i].p[0].y),2)+pow((r1->r[i].p[1].x-r1->r[i].p[0].x),2));
	d2=sqrt(pow((r1->r[i].p[2].y-r1->r[i].p[1].y),2)+pow((r1->r[i].p[2].x-r1->r[i].p[1].x),2));
	d3=sqrt(pow((r1->r[i].p[2].y-r1->r[i].p[0].y),2)+pow((r1->r[i].p[2].x-r1->r[i].p[0].x),2));
	if((d1>d2)&&(d1>d3))
	{
		r1->r[i].l=d2;
		r1->r[i].b=d3;
	}
	if((d2>d1)&&(d2>d3))
	{
		r1->r[i].l=d1;
		r1->r[i].b=d3;	
	}
	if((d3>d1)&&(d3>d2))
	{
		r1->r[i].l=d1;
		r1->r[i].b=d2;
	}
	}
	
}

void get_area(struct rectangles *r1)
{
	for(int i=0;i<r1->n;i++)
	{
	r1->r[i].area=(r1->r[i].l)*(r1->r[i].b);
    	}
}
void output(struct rectangles r1)
{
	printf("Area of ");
	for(int i=0;i<r1.n;i++)
	{
        printf("(%f,%f),(%f,%f),(%f,%f) is %f\n",r1.r[i].p->x,r1.r[i].p->y,r1.r[i+1].p->x,r1.r[i+1].p->y,r1.r[i+2].p->x,r1.r[i+2].p->y,r1.r[i].area);
	}
}
void main()
{
	
	struct rectangles r1;
	get_instance(&r1);
	input(&r1);
	get_distances(&r1);
	get_area(&r1);
	output(r1);
	
	
}
