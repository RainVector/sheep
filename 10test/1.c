#include <stdio.h>
double multi(int n);
double Pow(double x,int y);
int main()
{
	double x;
while(	scanf("%lf",&x) != EOF)
{

	int flag = 1;
	int i,acc=20;
	double sum = 0;
	for(i=0;i<acc;i++)
	{
		double data;
		double resu;
		data = multi(2*i); //get Factorial(fen zi)
		
		resu = Pow(x,2*i); //get Denominator(fen mu)
		
		sum = sum + (double)(flag * resu/data);
		flag = -flag;
	}
	printf("cos(%g)=%g\n",x,sum);
}
	return 0;
}
double multi(int n)
{
	int i;
	double result=1;
	for(i=1;i<=n;i++)	
			result = result * i;
	return result;
}
double Pow(double x,int  y)
{
	int i;
	double result=1;
	for(i=0;i<y;i++)
		result = result * x;
	return result;
}
