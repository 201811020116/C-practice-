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
    cout<<"������"<<this->name<<endl<<"�Ա�"<<this->gender<<endl<<"ѧ�ţ�"<<this->id<<endl<<"�ɼ�"<<this->score<<endl<<"�о�����"<<this->research<<endl<<"��ʦ"<<endl;
}
void Graduate::fun()const
{
    cout<<"������"<<this->name<<endl<<"�Ա�"<<this->gender<<endl<<"ѧ�ţ�"<<this->id<<endl<<"�ɼ�"<<this->score<<endl<<"�о�����"<<this->research<<endl<<"��ʦ"<<endl;
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
            cout<<"�ɼ��ȼ�Ϊ��E";
        case 6:
            cout<<"�ɼ��ȼ�Ϊ��D";
        case 7:
            cout<<"�ɼ��ȼ�Ϊ��C";
        case 8:
            cout<<"�ɼ��ȼ�Ϊ��B";
        case 9:
        case 10:
            cout<<"�ɼ��ȼ�Ϊ��A";
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
    cout<<"lucy�ĳɼ��ȼ�Ϊ�� "<<Grade(90.00)<<endl;
    cout<<"tim�ĳɼ��ȼ�Ϊ�� "<<Grade(84.50)<<endl;
    cout<<"lucy,tim���˵�ƽ���ɼ�Ϊ��"<<g1.aver(g2,2);
    system("pause");
    return 0;
}