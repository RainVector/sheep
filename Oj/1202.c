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
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n-1-i;j++)
				if(a[j]>a[j+1])
				{
					int temp;
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
