//给定数字，将0翻译为'a',1翻译为'b',25翻译为'z'，计算一个数字有多少翻译方法
#include<iostream>
using namespace std;
/*num=x1x2...xn
设x1x2..xi-2翻译数量为f(i-2)
设x1x2...xi-1翻译数量为f(i-1)
则整体翻译x1x2..xi方案数为f(i-2)
单独翻译xi时方案数f(i-1)

f(i)=f(i-2)+f(i-1) 当xi-1xi可被翻译
f(i)=f(i-1) xi-1xi不可翻译
*/
int translateNum(int num)
{

}

int main()
{

}