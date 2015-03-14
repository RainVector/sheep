#include <stdio.h>

int getCom(int a,int b);
int main()
{
	int m,n;// m is fenzi,n is fen mu
	int common;
	scanf("%d %d",&m,&n);
	common = getCom(m,n);
	m = m / common;
	n = n / common;
	printf("%d/%d\n",m,n);
	return 0;
}
int getCom(int a,int b)
{
	int maxCom = 1;
	int i = 1;
	for(;i<=a;i++)
			if(a%i==0&&b%i==0)
					maxCom = i;
					
	return maxCom;
}
