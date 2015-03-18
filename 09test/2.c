#include <stdio.h>
#include <malloc.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			return 0;
		int i,j;
		int *a = (int *)malloc(n*sizeof(int));
		int *b = (int *)malloc(n*sizeof(int));

		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i] = a[i];
		}
		for(i=0;i<n;i++)
			for(j=0;j<n-1-i;j++)
				if(a[j]>a[j+1])
				{
					int temp;
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
		//qu chong fu shu
		int co = 0;
		for(i=0;i<n;i++)
			if(a[i]==a[i+1])
				continue;
			else
				a[co++] = a[i];

		int order = 1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(b[i] == a[j])	
				{
					b[i] = j+1;
					continue;
				}
		for(i=0;i<n;i++)
			printf("%d ",b[i]);		
		printf("\n");
	}
	return 0;
}
