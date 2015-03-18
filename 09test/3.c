#include <stdio.h>
#include <string.h>

int IsSame(char des[],char sou[],int pos,int length);
int main()
{
	FILE *fp1,*fp2;
	char str[100];
	char input[10];
	fp1 = fopen("./in.txt","r");	
	fp2 = fopen("./out.txt","w+");

	memset(str,'\0',100*sizeof(char));
	fgets(str,100*sizeof(char),fp1);

	scanf("%s",input);
		int i,con = 0;
		int len = strlen(input);
		int pos = 0;
		while(str[i] != '\0')
		{

				if(str[i] ==input[0])
				{
					int same = IsSame(str,input,i,len);

					if(same == 1)
					{
						i = i+len;
					}
					else
						str[con++] = str[i++];
				}
				else
					str[con++] = str[i++];
		}
		str[con] = '\0';
		fputs(str,fp2);
	
	close(fp1);
	close(fp2);

	return 0;
}
int IsSame(char des[],char sou[],int pos,int length)
{
	int same = 1;
	int i;
	for(i=0;i<length;i++)
		if(des[pos+i] != sou[i])	
				same = 0;
	return same;
}
