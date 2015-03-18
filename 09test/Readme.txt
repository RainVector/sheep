1、【问题描述】
立方根的逼近迭代方程是 y(n+1) = y(n)*2/3 + x/(3*y(n)*y(n)),其中y0=x.求给定的x经过n次迭代后立方根的值。
输入：
输入有多组数据。
每组一行，输入x n。
输出：
迭代n次后的立方根，double精度,保留小数点后面六位。
样例输入：
3000000 28
样例输出：
144.224957
2、数组排序
输入一个数组的值,求出各个值从小到大排序后的次序。
输入:输入的第一个数为数组的长度,后面的数为数组中的值,以空格分割
输出:各输入的值按从小到大排列的次序。
sample
input:
4
-3 75 12 -3
output:
1 3 2 1
3、字符串的查找删除
给定文件filein.txt 按要求输出fileout.txt。
输入: 无空格的字符串
输出: 将filein.txt删除输入的字符串(不区分大小写),输出至fileout.txt
sample
输入:in
输出:将filein.txt 中的In、IN、iN、in删除,每行中的空格全部提前至行首,输出至fileout.txt
filein.txt中的值为:
#include <stdio.h>
int main()
{
printf(" Hi ");
}
输出的fileout.txt为
#clude<stdio.h>
tma()
{
prtf("Hi");
}

