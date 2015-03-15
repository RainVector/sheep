#include <stdio.h>
#include <memory.h>

int main()
{
	int n; 
	int island[100][100];
	int record[100][100];
	int i,j;
	int area = 0;

	freopen("./in.txt","r",stdin);	
	memset(record,-1,100*4*sizeof(int));
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&island[i][j]);
			if(island[i][j]==1)
			{
				if(record[i][0]==-1)
				{
					record[i][0] = j;	
				}
				if(record[j][2]==-1)
				{
					record[j][2] = i;
				}
				record[i][1] = j;
				record[j][3] = i;
			}	
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
				if(island[i][j]==0&&j>record[i][0]&&j<record[i][1]\
								&&i>record[j][2]&&i<record[j][3])
						area++;
	printf("%d\n",area);
	return 0;
}
