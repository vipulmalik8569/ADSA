#include<stdio.h>
#include<stdlib.h>

long int  max_prod_slow(long int* ,long int );
long int  max_prod_fast(long int*,long int );
void main()
{
long int n,a[20];
while(1)
{
	n=(rand()%10) + 2;
	for(int j=0;j<n;j++)
		a[j]=rand()%100;
	
	for(int k=0;k<n;k++)
		printf("%ld ",a[k]);
	
long int slow = max_prod_slow(a,n);
printf("\nResult of slow algorithm : %ld\n",slow);

long int fast = max_prod_fast(a,n);
printf("Result of fast algorithm : %ld\n",fast);

if(slow != fast)
	break;
}
scanf("%ld",&n);
for(int i=0;i<n;i++)
	scanf("%ld",&a[i]);
printf("Result of slow algorithm : %ld\n",max_prod_slow(a,n));
printf("Result of fast algorithm : %ld\n",max_prod_fast(a,n));
getchar();
}


long int  max_prod_slow(long int *a,long int n)
{
long int prod=0,temp;
for(int j=0;j<n;j++)
{
	for(int k=j+1;k<n;k++)
	{
		temp = a[j] * a[k];
		if(temp > prod)
			prod=temp;
	}
}
return prod;
}

	
long int  max_prod_fast(long int *a,long int n)
{
long int max1=0,max2=0,temp;
for(int j=0;j<n;j++)
{
	if(a[j]>max1)
		max1=a[j];
	if(max1>max2)
	{
		temp=max1;
		max1=max2;
		max2=temp;
	}

}
return max1*max2;
}

