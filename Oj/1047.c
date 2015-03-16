#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int flag = 1;
		int i;
		if(n>1)
		{
			for(i=2;i<n;i++)
					if(n%i==0)
							flag = 0;
		}
		else if(n <=1)
				flag = 0;
		if(flag == 1)
				printf("yes\n");
		else
				printf("no\n");
	}
}
