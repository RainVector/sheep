#include <stdio.h>

int multi(int num);

int main()
{
	int n;
	printf("please input:\n");
	while(scanf("%d",&n)!=EOF)
	{
		int inte = 0; //integer part
		int rema = 0; //remainder part	
		int count = 0;
		int sum = 0;
		int a[10];
		int i;

		printf("%d,",n);
		inte = n /10;
		rema = n %10;
		for(;!(inte==0&&rema==0);)		
		{
			a[count] = rema;
			rema = inte %10;
			inte = inte /10;
			count++;
		}
		
		for(i=0;i<count;i++)
			sum += multi(a[i]);	
	
		for(i=count-1;i>0;i--)
				printf("%d!+",a[i]);
		printf("%d!",a[i]);
		printf("=%d",sum);
		printf("\r\n");
		if(n==sum)
				printf("Yes\n");
		else
				printf("No\n");
	}
	return 0;
}
int multi(int num)
{
	int i,val=1;
	for(i=1;i<=num;i++)
		val = val*i;
	return val;	
}

