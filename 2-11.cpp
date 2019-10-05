//2-11.cpp：用引用作参数修改对应实际参数变量的值
#include <iostream>
using namespace std;
void swap(int x,int &y)                	//调用之初参数传递就使得引用参数y成为
//本次调用对应实际参数变量的别名
{   int t=x;
    x=y;                            	//对值形参的修改不会影响对应的实参变量
    y=t;                                //形参y随对应实参变量的变化而变化
}
int main()
{   int a=3,b=5,c=10,d=20;
    cout<<"a="<<a<<"  b="<<b<<endl ; 	//输出交换前的a、b值
    swap(a,b);                       	//调用函数，参数传递相当于执行了 int &y=b;使引用参数y获得了初值
    cout<<"a="<<a<<"  b="<<b<<endl; 	//输出交换后的a、b值
    cout<<"c="<<c<<"  d="<<d<<endl; 	//输出交换前的c、d值
    swap(c,d) ;                      	//调用函数，参数传递相当于执行了 int &y=d; 使引用参数y获得了初值
    cout<<"c="<<c<<"  d="<<d<<endl; 	//输出交换后的c、d值
    return 0;
}
