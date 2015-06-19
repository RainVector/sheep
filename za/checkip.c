#include <stdio.h>
#define TRUE 1
#define FALSE 0

//ipaddress formate
typedef struct ipaddr
{
	int ipaddr1;
	int ipaddr2;
	int ipaddr3;
	int ipaddr4;
}IpAddress;
//check the validtion of ipaddress
int check(struct ipaddr ipaddress);

int main()
{
	int n;
	int a,b,c,d;
	struct ipaddr list[10];
	int i = 0;
	scanf("%d",&n);
	for(i;i < n;i++)
	{
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		list[i].ipaddr1 = a;
		list[i].ipaddr2 = b;
		list[i].ipaddr3 = c;
		list[i].ipaddr4 = d;
	}
	for(i = 0;i < n;i++)
	{
		if(check(list[i]))
			printf("YES!\r\n");
		else
			printf("NO!\r\n");
	}	
	return 0;
	
}

int check(struct ipaddr ipaddress)
{
	int  result;
	int a,b,c,d;
	a = ipaddress.ipaddr1;
	b = ipaddress.ipaddr2;
	c = ipaddress.ipaddr3;
	d = ipaddress.ipaddr4;
	result = a >= 0 && a <=255\
	&&b >= 0 && b <=255\
	&&c >= 0 && c <=255\
	&&d >= 0 && d <=255;
	return result;
}
