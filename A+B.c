#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int deal(char str[])
{
	int length; //the length of the string
	int i,j=0;
	int result; //string is translate to int
	char nstr[30];

	length = strlen(str);
	for(i = 0;i < length;i++)	
	{
		if(str[i] != ',')
		{
			nstr[j] = str[i];
			j++;
		}
	}
	result = atoi(nstr);	
	return result;
}
int main()
{
	char A[30],B[30];
	int re_a,re_b;
	scanf("%s",A);
	scanf("%s",B);
	printf("%s %s\r\n",A,B);

	re_a = deal(A);
	printf("re_a:%d\r\n",re_a);
	re_b = deal(B);
	printf("re_b:%d\r\n",re_b);

	printf("%d,%d,%d\r\n",re_a,re_b,re_a+re_b);

	return 0;	
}

