#include <iostream>
#include <cstring>
using namespace std;

class Graduate{
    char *name;
    bool gender;
    int id[20]{};
    double score;
    string research,tutor;
public:
    Graduate();
    Graduate(char *na, int id[20], double score, char research, char tutor, bool gender);
    Graduate(Graduate &r);
    ~Graduate();
    void fun();
    void fun() const;
    static double aver(Graduate &r,int n)
    {
        double aver =0;
        for(int i = 0; i < n; i ++)
        {
            aver += r.score;
        }
        return (double)aver/n;
    };
    friend double Grade(double );
};

Graduate::Graduate()
{
    char a='a';
    name= reinterpret_cast<char *>(a);
    id[20] = {12};
    gender=true;
    score=90;
    research='u';
    tutor='y';
    cout<<name<< ' '<< gender<<id<<' '<<score<<" "<< research<<' '<<tutor ;
}
Graduate::Graduate(char *na, int id[20], double score, char research, char tutor, bool gender=true)
{
    if(name!=NULL)
    {
        name = new char[strlen(na)+1];
        strcpy(name,na);
    }
    if(gender)
    {
        cout<<"man"<<endl;
    }
    else{
        cout<<"female"<<endl;
    }
    this->gender =gender;
    this->id[20]=id[20];
    this->score=score;
    this->research=research;
    this->tutor=tutor;
}
Graduate::Graduate(Graduate &r)
{
    if(r.name != NULL)
    {
        int len = strlen(r.name);
        this->name = new char[len+1];
        strcpy(this->name,r.name);
    }
    this->gender=r.gender;
    this->id[20]= r.id[20];
    this->score =r.score;
    this->research=r.research;
    this->tutor = r.tutor;
}
Graduate::~Graduate()
{
    delete []name;
}
void Graduate::fun()
{
    cout<<"姓名："<<this->name<<endl<<"性别："<<this->gender<<endl<<"学号："<<this->id<<endl<<"成绩"<<this->score<<endl<<"研究领域"<<this->research<<endl<<"导师"<<endl;
}
void Graduate::fun()const
{
    cout<<"姓名："<<this->name<<endl<<"性别："<<this->gender<<endl<<"学号："<<this->id<<endl<<"成绩"<<this->score<<endl<<"研究领域"<<this->research<<endl<<"导师"<<endl;
}
double Grade(double score)
{
    switch ((int)score/10)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout<<"成绩等级为：E";
        case 6:
            cout<<"成绩等级为：D";
        case 7:
            cout<<"成绩等级为：C";
        case 8:
            cout<<"成绩等级为：B";
        case 9:
        case 10:
            cout<<"成绩等级为：A";
    }
}
int main()
{
    Graduate g1(reinterpret_cast<char *>('l'), reinterpret_cast<int *>(123), 90.00, 'f', 'g','m');
    Graduate g2(reinterpret_cast<char *>('t'), reinterpret_cast<int *>(555), 84.50, 'k', 'o', 'w');
    Graduate g3(g1);
    Graduate g4;
    g1.fun();
    g2.fun();
    g3.fun();
    g4.fun();
    cout<<"lucy的成绩等级为： "<<Grade(90.00)<<endl;
    cout<<"tim的成绩等级为： "<<Grade(84.50)<<endl;
    cout<<"lucy,tim两人的平均成绩为："<<g1.aver(g2,2);
    system("pause");
    return 0;
}