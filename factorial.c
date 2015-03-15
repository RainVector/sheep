#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arraysum(int arr[])
{
	int i,arrsum=0;

	for(i=0;arr[i]!=-1;i++)
		arrsum +=arr[i];
	return arrsum;
}
int factorial(int n)
{
	int i,fac = 1;
	for(i = 1;i<=n;i++)
		fac = fac * i;
	return fac;
}
int main()
{
	int input;
	int intePart;
	int remainder;

	while(scanf("%d",&input) != EOF)
	{
		int i;
		int a[10];
		int sum;
		memset(a,-1,10*sizeof(int));
		
		intePart = input /10;
		remainder = input%10;
		for(i=0;;i++)
		{
			a[i] = factorial(remainder);
			remainder = intePart%10;
			intePart =	intePart/10;
			printf("%d ",a[i]);
			if(intePart ==0&&remainder==0)
				break;
		}
		sum = arraysum(a);
		printf("%d\r\n",sum);
		if(input == sum)
			printf("yes\r\n");
		else
			printf("no\r\n");
	}
}

