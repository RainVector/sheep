#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	while(scanf("%s",str)!=EOF)
	{
		if(str[0] == 'E')
				return 0;
		int zc=0,oc=0,jc=0;
		int i,len;
		len = strlen(str);
		for(i=0;i<len;i++)
		{
			if(str[i] == 'Z')
					zc++;
			else if(str[i] == 'O')
					oc++;
			else
					jc++;
		}

		for(i=0;i<len;i++)
		{
			if(zc>0)
			{
				printf("Z");
				zc--;
			}
			if(oc>0)
			{
				printf("O");
				oc--;
			}
			if(jc>0)
			{
				printf("J");
				jc--;
			}

		}
		printf("\n");
	}
	return 0;
}
