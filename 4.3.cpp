//example4_03.cpp: 定义主函数,定义对象并调用相应函数.
#include <iostream>                   //包含系统文件
using namespace std;
class Circle
{
private:
    double Radius;                    //定义圆的半径
    const double PI;             //定义一个常数据成员PI代表圆周率
public:
    Circle(double r=0):PI(301415926)
    {
        //PI=3.1415926;
        Radius=r;
    }
    double Area();                    //求圆的面积
    double Circumference();           //求圆的周长

};
int main( )
{
    Circle c1(3.5),c2;                 //定义类的两个对象，c2的半径用默认值
    cout<<"area of c1="<<c1.Area()<<" , circumference of c1="<<c1.Circumference()<<endl;
    cout<<"area of c2="<<c2.Area()<<" , circumference of c2="<<c2.Circumference()<<endl;
    return 0;
}

double Circle::Area( )        //求圆的面积
{
    PI=3.14;
    return PI*Radius*Radius;
}
double  Circle::Circumference()  //求圆的周长
{
    return 2*PI*Radius;
}