//2-08.cpp: 用宏定义实现两数相乘
#include <iostream>
using namespace std;
#define  Multiply( x,y) (x)*(y)   //x,y用括号括起来，防止进行简单的文本替换
int  main()
{
    int a=Multiply(3+4,2+3);  //展开后为:int a=3+4*2+3
    cout<<"a="<<a<<endl;
    return 0;
}