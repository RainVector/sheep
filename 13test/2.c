#include<stdio.h> 
#include<malloc.h> 
#include<math.h> 

int *site; //每行的棋子所放置的位置，注意下标从0开始 
int queen; //皇后的数目 
int count=0; //第几种放置的可能性 

//判断第n+1行的放置是否合适 
int IsOk(int n) 
{ 
int i; 
for(i=0;i<n;i++) 
{ 
if(site[i]==site[n]) //判断是否同在一水平线上
return 0; 
if(abs(site[i]-site[n])==n-i)//判断是否同在一斜线上 
return 0; 
} 
return 1; 
} 

//具体执行放置判断以及输出最终结果 
void Queen(int n) 
{ 
int i; 
if(queen==n) 
{ 
printf("NO.%d: ",++count); 
for(i=0;i<queen;i++) 
{ 
printf("%d ",site[i]); 
} 
printf("\n"); 
return; 
} 
else 
{ 
for(i=0;i<queen;i++) 
{ 
site[n]=i; 
if(IsOk(n)) 
Queen(n+1); //返回时是返回到上一行的调用
} 
} 
} 

void main() 
{ 
printf("定义皇后的数量:"); 
scanf("%d",&queen); 
site=(int *)malloc(queen*sizeof(int)); 
Queen(0); 
}
