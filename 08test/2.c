#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define xm

int Judge(int a[9][9],int b[9][9],int n);
int main()
{
	int n;
	int matrx1[9][9],matrx2[9][9];
#ifdef xm
	freopen("./in.txt","r",stdin);
#endif
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		if(n==0)
			return 0;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&matrx1[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&matrx2[i][j]);
		int angle;
		angle = Judge(matrx1,matrx2,n);
		printf("%d\n",angle);
	}
}

int Judge(int a[9][9],int b[9][9],int n)
{
		int equ=1,ran=1,inv=1,lan=1;
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(a[i][j]!=b[i][j])
						equ = 0;
				if(a[i][j]!=b[j][n-1-i])
						ran = 0;
				if(a[i][j] != b[n-1-i][n-1-j])
						inv = 0;
				if(a[i][j] != b[n-1-j][i])
						lan = 0;
			}
		if(equ==1)
				return 0;
		else if(ran==1)
				return 90;
		else if(inv ==1)
				return 180;
		else if(lan ==1)
				return 270;
		else
				return -1;
}
