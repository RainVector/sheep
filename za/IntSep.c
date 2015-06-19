/*某些整数能分解成若干个连续整数的和的形式，例如
    15 = 1 + 2＋3＋4＋5　
    15 = 4 + 5 + 6
    15 = 7 + 8
某些整数不能分解为连续整数的和，例如：16
* 输入：一个整数N（N <= 10000）
* 输出：整数N对应的所有分解组合，按照每个分解中的最小整数从小到大输出，
每个分解占一行，每个数字之间有一个空格（每行最后保留一个空格）；
如果没有任何分解组合，则输出NONE。
*/
#include <stdio.h>
int main()
{
	int n;
	int found = 0;
	while(scanf("%d",&n) != EOF)
	{
		int i,j;
	
		for(i = 1;i < n;i++)
			for(j = i+1;j <=n;j++)
			{
				int temp = i;
				if(n == (i+j)*(j-i+1)/2)
				{
					found = 1;
					printf("%d = ",n);
					for(temp;temp <=j;temp++)
						printf("%d ",temp);
					printf("\r\n");
				}
			}
		if(found == 0)
			printf("NONE!\r\n");
	}
	return 0;
}

