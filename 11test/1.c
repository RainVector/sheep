#include <stdio.h>

int yuSun(int input);

int main()
{
	int M,N;
	int A;
	int found = 0;
	scanf("%d %d",&M,&N);
	for(A = M;A<=N;A++)
	{
		int B;
		int yuB;
		B = yuSun(A);
		if(B>A&&B>M&&B<N)
		{
			yuB = yuSun(B);

			if(A==yuB)
			{
				found = 1;
				printf("%d %d\n",A,B);
			}
		}
	}
	if(found == 0)
			printf("NONE\n");

	return 0;
}
int yuSun(int input)
{
	int i,sum = 0;
	for(i=1;i<input;i++)
			if(input%i==0)
					sum += i;
	return sum;
}
