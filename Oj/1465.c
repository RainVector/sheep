#include <stdio.h>
#include <malloc.h>
#define XM
	
int Is(int a,int b);
int comyue(int m,int n);
int main()
{
	int n;
#ifdef XM
		freopen("./in.txt","r",stdin);
#endif
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			return 0;
		int *data = (int *)malloc(sizeof(int)*n);
		int i,j;
		int count = 0;

		for(i=0;i<n;i++)
			scanf("%d",&data[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(Is(data[i],data[j]))
					count++;
		printf("%d\n",count);

	}
	return 0;
}
int Is(int a,int b)
{
	if(a==0|| b==0)
			return 0;
	else if(a==1||b==1)
			return 1;
	else if(b%a==0)
			return 0;
	else if(comyue(a,b))
			return 0;
	else
			return 1;
}
int comyue(int m,int n)
{
	int i;
	for(i=2;i<m;i++)
			if(m%i==0&&n%i==0)
					return 1;
	return 0;
}
