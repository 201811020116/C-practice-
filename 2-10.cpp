//2-10.cpp：引用的声明及使用示例
#include <iostream>
using namespace std;
int x=5,y=10;
int &r;                                     	//定义一个引用r,并未同时对其进行初始化，程序报错
void print()                                    	//定义一个专门用于输出的函数
{    cout<<"x="<<x<<" y="<<y<<" r="<<r<<endl ;  	//输出x、y、r的值
    cout<<"Address of x "<<&x<<endl;        	//输出变量x的内存地址
    cout<<"Address of y "<<&y<<endl;          	//输出变量y的内存地址
    cout<<"Address of r "<<&r<<endl ;       		//输出引用r的内存地址
}
int main()
{
    print();                                   	//第1次调用输出函数
    r=y ;
    y=100 ;
    print() ;                                  	//再次调用输出函数
    x=200;
    print() ;                                  	//再次调用输出函数
    return 0;
}