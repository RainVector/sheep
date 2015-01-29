/*
*full-mark P and tolerance T(<P)
*to get the grad of student.
*1.|G1-G2|<T,grade = average of G1 and G2
*2.otherwise,we will use G3 and GJ
*  if G3 is within the tolerance with either G1 or G2,but not both,
*	the grade will be the average of G3 and closest grade
*  if G3 is within the tolerance with both G1 and G2,the grade will
*	be the maximum of the G1,G2 and G3
*  if G3 is within the tolerance with neither G1 and G2,the grade 
*	will be GJ
*/
#include <stdio.h>
int distance(int a,int b); //the abs of two numbers 
int max(int a,int b,int c); //the maximum of three numbers

int main()
{
	int P,T,G1,G2,G3,GJ;
	float grade;
	int d1,d2,d3;
	scanf("%d %d %d %d %d %d",&P,&T,&G1,&G2,&G3,&GJ);

	d1 = distance(G1,G2);
	d2 = distance(G1,G3);
	d3 = distance(G2,G3);
		
	if(d1 <=T)
		grade = (G1 + G2)/2;
	else if(d2<=T && d3 <=T)
		grade = max(G1,G2,G3);
	else if(d2<=T || d3<=T)
		grade =	(float)(G3 +(d2>d3?G2:G1)) / 2;
	else
		grade = GJ;
	printf("%.1f\r\n",grade);

	return 0;			
}
int distance(int a,int b)
{
	int distance;
	distance = a-b;
	if(distance>0)
		return distance;
	else
		return -distance;
}
int max(int a,int b,int c)
{
	int max = a;
	if(b > max)
		max = b;
	if(c > max)
		max = c;
	return max;
}
