#include <iostream>
#include "student.h"
#include <cstring>
using namespace std;

student::student(int age, const char id[12], char *name, std::string home)
{
    cout<<"���캯���Զ�����"<<endl;
    this->id[12] = id[12];
    this->age = age;
    this->home = home;
    if(name!= NULL)
    {
        int len = strlen(name);

        name = new char[len +1];

        strcpy((char*) name , name);
    }
}

student::student(const student &r)
{
    this->id[12] = id[12];
    this->age = age;
    this->home = home;
    if(r.name != NULL)
    {
        int len = strlen(r.name);
        this->name = new char[len+1];
        strcpy(this->name,r.name);
    }
}

student::~student() 
{
    delete []name;
}

std::basic_string<char> student::get()
{
    return home;
}
void student::set(int, char *id, char *name, std::string)
{
    this->id[12] = id[12];
    this->name = name;
    this->age = age;
    this->home = home;
}
void student::pf()
{
    cout<< "ѧ��id:"<<this->id <<endl;
    cout<<"����age:"<<this->age<<endl;
    cout<< "����name:"<<this->name <<endl;
    cout<<"��ַhome:"<<this->home<<endl;
}

int main()
{
    student li(19,"201811020116","lxl","jinan");
    student w = li;
    li.pf();
    w.pf();
    system("pause");
    return 0;
}
