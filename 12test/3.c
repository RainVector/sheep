#include <stdio.h>
#include <string.h>

#define MaxWordLen 300
void Remove(char str[]);
int IsDel(char ch);
int GetPos(char buf[],int pos,char word[]);

int main()
{
	char str[MaxWordLen];	
	int position = 0;
	char word[10];
	memset(word,'\0',10*sizeof(char));
	freopen("./in.txt","r",stdin);
	while(gets(str)!=NULL)
	{

	Remove(str); // Remove keyword in ""
	
	do{
		position = GetPos(str,position,word);
		int wlen = strlen(word);
		if(strcmp("if",word)==0)
		{
			printf("if:%d\n",position-wlen+1);
		}
		else if(strcmp("while",word)==0)
		{
			printf("while:%d\n",position-wlen+1);
		}
		else if(strcmp("for",word)==0)
		{
			printf("for:%d\n",position-wlen+1);
		}
	}while(position>0);
	}
	return 0;
	
}
void Remove(char str[])
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
	return (i>=len)?-1:i;
}
