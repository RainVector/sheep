#include <stdio.h>
#include <string.h>

#define STRLEN 30

int getFlag(char ch);

int main()
{
	char str[STRLEN];
	scanf("%s",str);
	int len;
	len = strlen(str)-1;
	int i;
	printf("%c",str[0]);
	for(i=1;i<len;i++)
		if(str[i]=='-')
		{
				int flag1,flag2;
				flag1 = getFlag(str[i-1]);
				flag2 = getFlag(str[i+1]);
				if(flag1==flag2)
				{
					int begin,end;
					for(begin = str[i-1]+1;begin<str[i+1];begin++)
							printf("%c",begin);
				}
				else
						printf("%c",str[i]);
		}
		else
				printf("%c",str[i]);
	printf("%c",str[i]);
	printf("\n");
	return 0;
}
int getFlag(char ch)
{
	if(ch >= 'a'&&ch <= 'z')
			return 1;
	else if(ch >= 'A'&&ch <= 'Z')
			return 2;
	else if(ch >='0'&&ch <='9')
			return 3;
}
