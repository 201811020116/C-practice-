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
    cout<<"������"<<this->name<<endl;
    if(gender)
    {
       cout<< "�Ա�male"<<endl;
    }
    else{
        cout<<"�Ա�female"<<endl;
    }
    cout<<"ѧ�ţ�"<<this->id<<endl<<"�ɼ�:"<<this->score<<endl<<"�о�����:"<<this->research<<endl<<"��ʦ:"<<this->tutor<<endl;
}
void Graduate::fun()const
{
    cout<<"-----����Ա����-----"<<endl<<"������"<<this->name<<endl;
    if(gender)
    {
        cout<< "�Ա�male"<<endl;
    }
    else{
        cout<<"�Ա�female"<<endl;
    }
    cout<<"ѧ�ţ�"<<this->id<<endl<<"�ɼ�:"<<this->score<<endl<<"�о�����:"<<this->research<<endl<<"��ʦ:"<<this->tutor<<endl;
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
            break;
        case 6:
            cout<<"�ɼ��ȼ�Ϊ��D";
            break;
        case 7:
            cout<<"�ɼ��ȼ�Ϊ��C";
            break;
        case 8:
            cout<<"�ɼ��ȼ�Ϊ��B";
            break;
        default:
            cout<<"�ɼ��ȼ�Ϊ��A";
            break;
    }
}
int main()
{
    Graduate g1("lxl", "201811020116", 90.00, "AI", "zqk1", true);
    Graduate g2("lzt", "201811020117", 84.50, "������Ӿ�", "zqk2", false);
    g1.fun();
    g2.fun();
    cout<<"lxl��"<<Grade(90.00)<<endl;
    cout<<"lzt"<<Grade(84.50)<<endl;
    cout<<"���˵�ƽ���ɼ�Ϊ��"<<Graduate::aver(g2,2);
    system("pause");
    return 0;
}