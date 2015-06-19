#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100]; 
	int len;  //the length of the string
	int i;

	gets(str);  //input the string
	len = strlen(str); //get the string's length
	puts(str); //print the string on the screen
	printf("%d\r\n",len); //print the length on the screen
	
	//print the inverted string
	for(i = len-1;i >=0;i--) 
		putchar(str[i]);
	printf("\r\n");
	
	return 0;

}
