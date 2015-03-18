#include <stdio.h>
#include <string.h>

int main()
{
	char s[100],c;
	memset(s,'\0',100*sizeof(char));
	while(scanf("%s %c",s,&c)!=EOF)
	{
		int i,con=0;
		int len;
		len = strlen(s);
		for(i=0;i<len;i++)
			if(s[i] != c)
					s[con++] = s[i];
		s[con] = '\0';
		printf("%s\n",s);	
		memset(s,'\0',100*sizeof(char));
	}
	return 0;
}
