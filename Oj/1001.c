#include <stdio.h>

int main()
{
	int col,row;
	while(scanf("%d",&col)!=EOF)
	{
		int a[10][10];
		int b[10][10];
		int i,j;
		int data;
		if(col == 0)
		{
			return 0;
		}
		scanf("%d",&row);
		for(i=0;i<col;i++)
			for(j=0;j<row;j++)
			{
				scanf("%d",&data);
				a[i][j] = data;	
			}
		for(i=0;i<col;i++)
			for(j=0;j<row;j++)
			{
				scanf("%d",&data);
				b[i][j] = data;	
			}
		for(i=0;i<col;i++)
			for(j=0;j<row;j++)
			{
				a[i][j] = a[i][j] + b[i][j];	
			}
		int count = 0;
		for(i=0;i<col;i++)
		{
			int IsZero = 1;
			for(j=0;j<row;j++)
			{
				if(a[i][j] != 0)	
					IsZero = 0;
			}
			if(IsZero == 1)		
					count++;
		}	
		for(j=0;j<row;j++)
		{
			int IsZero = 1;
			for(i=0;i<col;i++)
			{
				if(a[i][j] != 0)	
					IsZero = 0;
			}
			if(IsZero == 1)		
					count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
