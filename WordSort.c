#include <stdio.h>
#include <string.h>

void sort(char Iword[][10]);

int main()
{
	char str[10];
	char word[10][10];
	int i;
	printf("please input 10 word:\n");
	for(i=0;i<10;i++)
	{
		scanf("%s",word[i]);
	}
	sort(word);
	for(i=0;i<10;i++)
	{
		printf("%s\n",word[i]);
	}
	
	return 0;	
}
void sort(char Iword[][10])
{
	int i,j;
	char temp[10];
	for(i=0;i<10;i++)
			for(j=0;j<10-i;j++)
				if(strcmp(Iword[j],Iword[j+1])>0)
				{
					strcpy(temp,Iword[j]);
					strcpy(Iword[j],Iword[j+1]);
					strcpy(Iword[j+1],temp);
				}
}
