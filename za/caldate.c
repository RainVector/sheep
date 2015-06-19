/*
*input two integer y(1<=y<=3000),n(1<=n<=366)
*y means year,n means the nth day of the year
*output :the date formate:yyyy-mm-dd
*eg:
*Input:2000 3
*Output:2000-01-03
*/
#include <stdio.h>

int isLeap(int year)
{
	int Leap;
	Leap = (0 == year%4)&&(0 != year%100 || 0 == year%400);
	return Leap;
}
int main()
{
	
}
