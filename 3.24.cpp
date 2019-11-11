//li3_24.cpp：将类Date的成员函数Print（）作为类Student的友元成员示例
#include<iostream>
#include<string.h>
using namespace std;
class Date
{   int year, month, day ;     			//数据成员默认为是私有属性
public :                     			//下一行为普通构造函数声明
    Date( int y=2007 , int m=1 , int d=1 ) ;
    void Display ( Student &stu )       //成员函数，其形式参数为类Student的对象引用
    {   cout<< stu.specialty <<endl;               //先显示学生对象的专业名称
        cout<< year << "-" << month << "-" << day << endl;   //再显示本类当前对象代表的日期
    }
};
Date::Date(int y,int m,int d)  			//普通构造函数的定义
{   year = y;
    month = m;
    day = d;
    cout<<"Constructor called.\n";
}

class Student               	// Student后于Date定义，
{private:
    char *specialty;
public:
    Student(char  *pSpec);
    ~Student();
    friend void Date::Display (Student &);   //此为声明友元成员的语句，Date::不可少
};

Student::Student(char *pSpec)                  //Student类的构造函数定义
{   if ( pSpec )
    {	specialty = new char[strlen( pSpec ) + 1];
        strcpy( specialty, pSpec );
    }
    else specialty = 0;
}
Student::~Student( )                           //Student类的析构函数定义
{  if ( specialty )
        delete [ ]specialty;
}

int main( )
{   Student zhang("computer");
    Date Birthday( 1990,10,17 );
    Birthday. Display ( zhang );       	      //通过Date类对象Birthday调用函数也同时显示对象zhang的信息
    return 0;
}