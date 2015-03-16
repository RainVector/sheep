#include <stdio.h>

#define XMW

int main()
{
	int col1,row1;
	int col2,row2;
	int i,j;
	int matr1[10][10];
	int matr2[10][10];
	int col3,row3;
	
#ifdef XMW
	freopen("./in.txt","r",stdin);
#endif

	scanf("%d %d",&col1,&row1);
	for(i=0;i<col1;i++)
		for(j=0;j<row1;j++)
			scanf("%d",&matr1[i][j]);
	scanf("%d %d",&col2,&row2);
	for(i=0;i<col2;i++)
		for(j=0;j<row2;j++)
			scanf("%d",&matr2[i][j]);
	scanf("%d %d",&col3,&row3);
	int m,n;
	for(i=col3-1,m=0;i<col1&&m<col2;i++,m++)
		for(j=row3-1,n=0;j<row1&&n<row2;j++,n++)
			matr1[i][j] = matr2[m][n];			
	for(i=0;i<col1;i++)
		for(j=0;j<row1;j++)
		{
			printf("%d ",matr1[i][j]);
			if(j==row1-1)
					printf("\n");
		}
	return 0;	
}
