#include <stdio.h>
#define MAXROW	10
#define MAXCOLUMN 100
int main()
{
	int row,column;//for matrix
	int num;//input number
	int a[10][10]={0},b[10][10]={0};

	while(1)
	{
		int count = 0,sum = 0;
		scanf("%d",&row);
		while(row == 0)
			return 0;
		scanf("%d",&column);
		
		int i,j;
		for(i = 0;i < row;i++)
			for(j=0;j<column;j++)
				{
					scanf("%d",&num);
					a[i][j] = num;
				}
		for(i = 0;i < row;i++)
			for(j=0;j<column;j++)
				{
					scanf("%d",&num);
					b[i][j] = num;
				}
			
		for(i = 0;i < row;i++)
		{
			for(j=0;j<column;j++)
				sum = a[i][j] + b[i][j];	
			if(sum == 0)
				count++;
		}	
		for(j = 0;j < column;j++)
		{
			for(i = 0;i < row;i++)
				sum = a[i][j] + b[i][j];	
			if(sum == 0)
				count++;
		}	
		printf("%d",count);	
	}	
	return 0;
}
