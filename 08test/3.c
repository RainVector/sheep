#include <stdio.h>
#include <string.h>
#include <malloc.h>

void process(char str[],char word[]);
int main()
{
	char *str[10];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int i;
		char word[5];	
		for(i=0;i<n;i++)
		{
			str[i] = (char *)malloc(10*sizeof(char));
			scanf("%s",str[i]);			
		}
		scanf("%s",word);
		int wlen = wordlen(word);

		for(i=0;i<n;i++)
			for(j=0;j<strlen(str[i];j++);
			if(equel(str[i][j],word[0]))
				process(str[i],word,j,wlen);
	}
	return 0;
}
void process(char str[],char word[],int pos,int wlen)
{
	int i,len;
	len = strlen(str);
	for(i=pos;i<len;i++)
		if(str)
}
int wordlen(char str[])
{
	int i;
	int len = strlen(str);
	int wlen = 0;
	for(i=0;i<n;i++)
		if(str[i] == '[')
		{
			while(str[++i] != ']');
		}
		else
				wlen++;
	wlen++;
	return wlen;		
}
int equel(char ch1,char ch2)
{
	char val1,val2;
	if(ch1>'A'&&ch1<'Z')
			ch1 = ch1 + 32;
	if(ch2>'A'&&ch2<'Z')
			ch2 = ch2 + 32;
	if(ch1==ch2)	
			return 1;
	else 
			return 0;
}
