#include <stdio.h>

int main()
{
	double x;
	int n;
	while(scanf("%lg %d",&x,&n)!=EOF)
	{
			if(n == 0)
					return 0;
		double y = x;
		int i;
		for(i=0;i<n;i++)
			y = 2*y/3 + x/(3*y*y);
		printf("%.6f\n",y);
	}
	return 0;
}
