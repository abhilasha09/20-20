#include<stdio.h>
struct efrac
{
	int den;
};
struct fraction
{
	int num,den;
};
void input(int n,struct efrac a[])
{
	for(int i=0;i<n;i++)
	{
		printf("Enter denominator of egyptian fraction %d",i+1);
		scanf("%d",&a[i].den);
	}
}
struct fraction compute(int n,struct efrac a[])
{
	struct fraction f;
	f.num=0;
	f.den=1;
	for(int i=0;i<n;i++)
	{
		f.den=f.den*a[i].den;
	}
	for(int i=0;i<n;i++)
	{
		f.num=f.num+(f.den)/(a[i].den);
	}
	int s;
	s=f.den;
	for(int i=1;i<=s;i++)
	{
		if((f.num%i==0)&&(f.den%i==0))
		{
			f.num=f.num/i;
			f.den=f.den/i;
		}
	}
	return f;
}
void output(struct fraction f)
{
	printf("%d/%d",f.num,f.den);
}
int main()
{
	int n;
	printf("enter the no.of egyptian fractions");
	scanf("%d",&n);
	struct efrac a[n];
	struct fraction f;
	input(n,a);
	f=compute(n,a);
	output(f);
	return 0;
}

