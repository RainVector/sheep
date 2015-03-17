#include <stdio.h>
#include <malloc.h>
#define xm

void sort(int arr[],int n);
int main()
{
	int num;
	int i;
#ifdef xm
	freopen("./in.txt","r",stdin);
#endif
	while(scanf("%d",&num)!=EOF)
	{
		if(num==0)
			return 0;
		int *a = (int *)malloc(num*sizeof(int));
		int *b = (int *)malloc(num*sizeof(int));
		for(i=0;i<num;i++)	
			scanf("%d",&a[i]);
		for(i=0;i<num;i++)	
			scanf("%d",&b[i]);
		int same = 1;
		sort(a,num);
		sort(b,num);
		for(i=0;i<num;i++)
			if(a[i]!=b[i])
				same = 0;
		if(same == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
void sort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)	
		for(j=0;j<n-1-i;j++)
				if(arr[j]>arr[j+1])
				{
					int temp;
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
}
