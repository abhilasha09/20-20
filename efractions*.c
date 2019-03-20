#include<stdio.h>
struct efrac
{
	int den[1000];
};
struct fraction
{
	int num,den;
};
void input(int n,struct efrac *a)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter denominator of egyptian fraction %d",i+1);
		scanf("%d",&a->den[i]);
	}
}
void compute(int n,struct efrac a,struct fraction *f)
{
	f->num=0;
	f->den=1;
	for(int i=0;i<n;i++)
	{
		f->den=f->den*a.den[i];
	}
	for(int i=0;i<n;i++)
	{
		f->num=f->num+(f->den)/(a.den[i]);
	}
	int s;
	s=f->den;
	for(int i=1;i<=s;i++)
	{
		if((f->num%i==0)&&(f->den%i==0))
		{
			f->num=f->num/i;
			f->den=f->den/i;
		}
	}
	
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
	struct efrac a;
	struct fraction f;
	input(n,&a);
    	compute(n,a,&f);
	output(f);
	return 0;
}
