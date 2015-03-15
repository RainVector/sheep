#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(n==0)
			return 0;
		int count = 0;
		while(n!=1)
		{
			if(n%2==0)	
				n = n/2;
			else
				n = (3*n+1)/2;
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
