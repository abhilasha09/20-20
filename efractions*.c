#include<stdio.h>
#include<math.h>
struct fraction
{
	int num,den;
};
int input(struct fraction *f)
{
	printf("Enter the numerrator");
	scanf("%d",&f->num);
	printf("Enter the denominator");
	scanf("%d",&f->den);
}
struct fraction subtract(struct fraction f,struct fraction a)
{
	struct fraction f1;
	f1.den=((f.den)*(a.den));
	f1.num=((f.num)*(a.den))-((a.num)*(f.den));
	return f1;
}

struct fraction compute(struct fraction f,int *d,struct fraction c[])
{
	struct fraction f1,z;
	f1=f;
	double a;
	a=(double)(f.den)/(double)(f.num);
	int b;
	b=ceil(a);
	d=0;
	c[*d].num=1;
	c[*d].den=b;
	z.num=f1.num;
	z.den=f1.den;
	struct fraction f2=subtract(f1,z);
	while(b!=0)
	{
		++d;
		if(f1.num==1)
		{
		c[*d].num=f2.num;
		c[*d].den=f2.den;
		z.num=f2.num;
		z.den=f2.den;
		break;
	}
	else
	{
	a=(double)(f2.den)/(double)(f2.num);
	int b;
	b=ceil(a);
	c[*d].num=1;
	c[*d].den=b;
	z.num=1;
	z.den=b;
	struct fraction f3=(f2,z); 
	}
	}

}
void output(int d,struct fraction c[],struct fraction f)
{
	printf("%d/%d=",f.num,f.den);
	for(int i=0;i<d;i++)
	{
		int m,n;
		m=c[i].num;
		n=c[i].den;
		printf("%d/%d +",m,n);
	}
}
void main()
{
	struct fraction f;int d;
	input(&f);
	struct fraction c[100];
	compute(f,&d,c);
	output(d,c,f);
}



