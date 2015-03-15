#include <stdio.h>
#include <string.h>

void remove(char str[]);
int IsDel(char ch);
int GetPos(char buf[],int pos,char word[]);

int main()
{
	char str[100];	
	int position = 0;
	char word[10];
	memset(word,'\0',10*sizeof(char));
	freopen("./in.txt","r",stdin);
	gets(str);	

	remove(str); // remove keyword in ""
	
	int i;
	int len;
	len = strlen(buf);
	do{
		position = GetPos(buf,position,word);
		int wlen = strlen(word);
		if(strcmp("if",word))
		{
			prinft("if:%d\n",position-wlen+1);
		}
		else if(strcmp("while",word))
		{
			printf("while:%d\n",position-wlen+1);
		}
		else if(strcmp("for",word))
		{
			printf("for:%d\n",position-wlen+1);
	}while(positon>0);
	
}
void remove(char str[])
{
	int i,len;
	len = strlen(str);
	for(i=0;i<len;i++)
			if(str[i]=='"')
			{
				i++;
				while(str[i]!='"')
				{
					str[i] = '#';
					i++;
				}
			}
}
int IsDel(char ch)
{
	int Del = 0;
	switch (ch)
	{
		case ',':
		case ' ':
		case '.':
		case '{':
		case '}':
		case '(':
		case ')':
		case '"':
		case ';':
		case '#':
		case '<':
		case '>':
		case '=':
				return 1;
		default:
				return 0;
	}
}
int GetPos(char buf[],int pos,char word[])
{
	int i,j=0;
	int begin = 0;
	int len = strlen(buf);
	
	for(i=pos;i<len;i++)
	{
		if(IsDel(buf[i]))
		{
				if(begin==0)
					continue;
				else
					break;
		}
		else
		{
			begin = 1;
			word[j] = buf[i];
			j++;
		}
	}
	word[j] = '\0';
	return (i>len)?-1:i;
}
