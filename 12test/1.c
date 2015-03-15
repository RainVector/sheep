#include <stdio.h>

int main()
{
	int input;
	int i,j;
	while(scanf("%d",&input)!=EOF)
	{
	int found = 0;
	for(i=1;i<input;i++)
			for(j=i+1;j<input;j++)
			{
				int sum;
				sum = (i+j)*(j-i+1)/2;
				if(sum == input)
				{
					int temp;
					found = 1;
					for(temp=i;temp<=j;temp++)
							printf("%d ",temp);
					printf("\n");
				}
				continue;
			}	
	if(found==0)
			printf("NONE!\n");
	}
	return 0;
}
