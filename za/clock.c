#include <stdio.h>
float uarch(float a,float b);

int main()
{
	unsigned int hour,minute;
	float rad_h,rad_m;
	float arch;

//	printf("please input time:");
	scanf("%d:%d",&hour,&minute);
//	printf("hour:%d,minute:%d.\r\n",hour,minute);

	rad_h = (hour%12)*30+((float)minute)/2;		
	rad_m = (minute%60)*6;

	arch = uarch(rad_h,rad_m);
	if(arch > 180)
		arch = 360 - arch;
	printf("%.2f\r\n",arch);
	return 0;
}
float uarch(float a,float b)
{
	float c;
	if(a > b)
		c = a-b;
	else
		c = b-a;
	return c;	
}
