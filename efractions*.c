#include<stdio.h>
struct efrac
{	
	int den[1000];
	int nden;
};
struct fraction
{
	int num,den;
};
void input(int n1,struct efrac a[n1])
{
	int n;
	for(int j=0;j<n1;j++)
	{
	printf("enter the no.of denominators for efrac %d",j+1);
	scanf("%d",&a[j].nden);
	for(int i=0;i<a[j].nden;i++)
	{
		printf("Enter denominator %d of egyptian fraction %d",i+1,j+1);
		scanf("%d",&a[j].den[i]);
	}
	}
}
void compute(int n1,struct efrac a[n1],struct fraction f[n1])
{
	int s,n;
	for(int j=0;j<n1;j++)
	{
	f[j].num=0;
	f[j].den=1;
	for(int i=0;i<a[j].nden;i++)
	{
		f[j].den=f[j].den*a[j].den[i];
	}
	
	s=f[j].den;
	}
	for(int j=0;j<n1;j++)
	{
	for(int i=0;i<a[j].nden;i++)
	{
		f[j].num=f[j].num+(f[j].den)/(a[j].den[i]);
	}
	}
	
	
	for(int j=0;j<n1;j++)
	{
	for(int i=1;i<=s;i++)
	{
		
		if((f[j].num%i==0)&&(f[j].den%i==0))
		{
			f[j].num=f[j].num/i;
			f[j].den=f[j].den/i;
		}
	}
	}
}
void output(int n1,struct fraction f[n1])
{
	for(int i=0;i<n1;i++)
	printf("%d/%d\n",f[i].num,f[i].den);
}
int main()
{
	int n1;
	printf("Enter the number of egyptian fractions\n");
	scanf("%d",&n1);
	
	struct efrac a[n1];
	struct fraction f[n1];
	input(n1,a);
    	compute(n1,a,f);
	output(n1,f);
	return 0;
}
