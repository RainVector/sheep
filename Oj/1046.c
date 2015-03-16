#include <stdio.h>

int main()
{
	int a[10];
	while(scanf("%d",&a[0])!=EOF)
	{
		int i;
		for(i=1;i<10;i++)
				scanf("%d",&a[i]);
		int max = a[0];
		for(i=1;i<10;i++)
				if(max < a[i])
						max = a[i];
		printf("max=%d\n",max);
	}
	return 0;
}
