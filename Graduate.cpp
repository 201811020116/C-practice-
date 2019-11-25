#include <iostream>
#include <cstring>
using namespace std;

class Graduate{
    char *name;
    bool gender;
    char id[20];
    double score;
    string research,tutor;
public:
    Graduate();
    Graduate(const char *na, const char id[20], double score, string research, string tutor, bool gender);
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
    cout<<"conducter is called.";
}
Graduate::Graduate(const char *na, const char id[20], double score,string research, string tutor, bool gender)
{
    if(name!=NULL)
    {
        name = new char[strlen(na)+1];
        strcpy(name,na);
    }
    this->gender =gender;
   strcpy(this->id,id);
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
    cout<<"姓名："<<this->name<<endl;
    if(gender)
    {
       cout<< "性别：male"<<endl;
    }
    else{
        cout<<"性别：female"<<endl;
    }
    cout<<"学号："<<this->id<<endl<<"成绩:"<<this->score<<endl<<"研究领域:"<<this->research<<endl<<"导师:"<<this->tutor<<endl;
}
void Graduate::fun()const
{
    cout<<"-----常成员函数-----"<<endl<<"姓名："<<this->name<<endl;
    if(gender)
    {
        cout<< "性别：male"<<endl;
    }
    else{
        cout<<"性别：female"<<endl;
    }
    cout<<"学号："<<this->id<<endl<<"成绩:"<<this->score<<endl<<"研究领域:"<<this->research<<endl<<"导师:"<<this->tutor<<endl;
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
            break;
        case 6:
            cout<<"成绩等级为：D";
            break;
        case 7:
            cout<<"成绩等级为：C";
            break;
        case 8:
            cout<<"成绩等级为：B";
            break;
        default:
            cout<<"成绩等级为：A";
            break;
    }
}
int main()
{
    Graduate g1("lxl", "201811020116", 90.00, "AI", "zqk1", true);
    Graduate g2("lzt", "201811020117", 84.50, "计算机视觉", "zqk2", false);
    g1.fun();
    g2.fun();
    cout<<"lxl的"<<Grade(90.00)<<endl;
    cout<<"lzt"<<Grade(84.50)<<endl;
    cout<<"两人的平均成绩为："<<Graduate::aver(g2,2);
    system("pause");
    return 0;
}