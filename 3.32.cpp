#include <iostream>
#include <string.h>
using namespace std;
class Student
{
    int age;
    char *name;
public:
    Student(int m, const char *(n)) //定义构造函数
    {
        age = m;
        name = new char[strlen(reinterpret_cast<const char *>(n)) + 1]; //给name申请动态内存
        strcpy(name, reinterpret_cast<const char *>(n));  //将字符串n拷贝给name
    }
    friend void disp(Student &); //声明友元函数
    ~Student()  //声明定义析构函数
    {
        cout<<"delete it."<<name<<endl;
        delete []name;
    }
};
void disp(Student &p) //友元函数的实现
{
    cout<<"student's name is "<<p.name<<",age is "<<p.age<<endl;
}

int main()
{
    Student A(18,"wujiang"); //创建对象A
    Student B(19,"xiayu");  //创建对象B
    disp(A); //输出对象A的值
    disp(B); //输出对象B的值
    return 0;
}
