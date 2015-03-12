#include <stdio.h>
#include <string.h>

int main()
{
	char buff[100];
	char word[100][100];
	int i = 0;  //the number of word
	int max = 0;
	int j;
	int pos;

	scanf("%d",&pos);
	printf("the postion is%d\n",pos);

	fflush(stdin);
	freopen("./in.txt","r",stdin);

	while(gets(buff)!=NULL)
	{
		int tem=0,tem1=0;
		for(;buff[tem]!=':';tem++)
				word[i][tem] = buff[tem];
		tem++;
		i++;
		for(;buff[tem]!='\0';tem++)
		{
				word[i][tem1] = buff[tem];
				tem1++;
		}
		i++;
		/*
		char *token;
		char del[2] = ":";
		token = strtok(buff,del);
		while(token!=NULL)
		{
			word[i] = token;
			token = strtok(buff,del);
			i++;
		}
		*/
	}

	for(j=0;j<i;j++)
	{
		int len;
		len = strlen(word[j]);
		if(len>max)
				max = len;
	}

	for(j=0;j<i;j=j+2)
	{
		int len;
		int x;
		len = strlen(word[j]);
		for(x=0;x<pos-len-1;x++)
				printf(" ");
		printf("%s : ",word[j]);
		printf("%s",word[j+1]);	
		printf("\n");
	}

	return 0;
}
