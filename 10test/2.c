#include <stdio.h>
#include <string.h>

#define Strlen 100
#define xm

int main()
{
	char str1[Strlen],str2[Strlen];
	memset(str1,'\0',Strlen*sizeof(char));
	memset(str2,'\0',Strlen*sizeof(char));
	int len1,len2;
#ifdef xm
	freopen("./in.txt","r",stdin);
#endif
	scanf("%s",str1);	
	scanf("%s",str2);	

	len1 = strlen(str1);
	len2 = strlen(str2);
	
	int i,j;
	int same = 0,con = 0;
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
				if(str1[i]==str2[j])
						same = 1;
		if(same == 0)
		{
			str1[con] = str1[i];	
			con ++;
		}
		same = 0;
	}
	str1[con] = '\0';
	printf("%s\n",str1);
	printf("%s\n",str2);
	
	
	char str3[100];
	memset(str3,'\0',100*sizeof(char));
	int m=0,n=0;
	i = 0;
	while(str1[m]!='\0'&&str2[n]!='\0')
			if(str1[m] < str2[n])
					str3[i++] = str1[m++];
			else
					str3[i++] = str2[n++];
	while(str1[m]!='\0')
			str3[i++] = str1[m++];
	while(str2[n]!='\0')
			str3[i++] = str2[n++];
	str3[++i] = '\0';

	printf("%s\n",str3);

	return 0;
}
