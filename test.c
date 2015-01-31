#include <stdio.h>

char *test(char str[])
{
	int length;
	int i = 0;
	static	char nstr[30];
	length = strlen(str);
	for(i;i < length;i++)
		nstr[i] = str[i];
	return nstr;
}
int main()
{
	char sstr[30],dstr[30];
	scanf("%s",sstr);
	scanf("%s",dstr);
	
	char *p;
	p = test(sstr);
	printf("%s\r\n",p);
	p = test(dstr);
	printf("%s\r\n",p);
	return 0;
}
