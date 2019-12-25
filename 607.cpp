#include <iostream>
using namespace std;
class Date
{
    int year, month, day ;     			//数据成员默认为是私有属性
public :                     			//下一行为普通构造函数声明
    Date(int y=2011,int m=8,int d=30) ;
    friend ostream & operator<<(ostream & out, const Date &);		//友元函数重载输出运算符"<<"
    friend istream & operator >> (istream & in, Date &); 		//友元函数输入重载运算符">>"
};
Date::Date(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
ostream & operator<<(ostream & out, const Date & obj)
{
    out <<obj.year;
    out << "-";
    out <<obj.month;
    out << "-";
    out <<obj.day;
    out <<endl;
    return out;
}
istream & operator >> (istream & in, Date & obj)
{
    cout << "Input year, month, day of the Date:\n";
    in>>obj.year;
    in>>obj.month;
    in>>obj.day;
    return in;
}

int main(){
    Date d1,d2(2019,12,20),d3;
    cin>>d3;
    cout<<"the value of d1 is :"<<d1;
    cout<<"the value of d2 is :"<<d2;
    cout<<"the value of d3 is :"<<d3;
    cout<<d1<<d2<<d3;
    return 0;

}