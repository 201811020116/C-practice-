#include <iostream>                   //包含系统文件
using namespace std;
class Circle
{
private:
    double Radius;                    //定义圆的半径
    const double PI;             //定义一个常数据成员PI代表圆周率
public:
    Circle(double r=0): PI(3.1415926) //只能通过初始化列表初始化常数据成员
    {
        Radius=r;
    }
    double Area();                    //求圆的面积
    double Circumference();           //求圆的周长
    double GetRadius( )const ;

};
double Circle::Area( )                  //求圆的面积
{
   //Radius*=2;
    double a=GetRadius();
    return PI*Radius*Radius;
}
double  Circle::Circumference()         //求圆的周长
{	return 2*PI*Radius;
}
double Circle::GetRadius()const         //常成员函数，获取半径值的实现代码，此例新增加
{
    //double a = Area();
   // Radius*=2;
    return Radius;
}
int main( )
{
    Circle c1(3.5),c2;                 //定义类的两个对象，c2的半径用默认值
    cout<<"radius of c1="<<c1. GetRadius ();
    cout<<" , area of c1="<<c1.Area()<<" , circumference of c1="<<c1.Circumference()<<endl;
    cout<<"radius of c2="<<c2. GetRadius ();
    cout<<" , area of c2="<<c2.Area()<<" , circumference of c2="<<c2.Circumference()<<endl;
    return 0;
}

