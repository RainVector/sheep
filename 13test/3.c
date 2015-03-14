#include <stdio.h>
int main()
{
	double input;
	int count = 0;
	scanf("%lf",&input);
	if(input>10)
	{	
		while(input > 10)
		{
			input = input /10;
			count++;
		}
		printf("%ge%d\n",input,count);
	}
	else if(input < 1)
	{
		while(input < 1)
		{
			input = input * 10;
			count--;
		}
		printf("%ge%d\n",input,count);
	}
	else
		printf("%g\n",input);
	getchar();
	return 0;
}
