#include <iostream>
#include <math.h>
using namespace std;

class triangle
{
    private:
        double a,b,c;
    public:
        double init(double,double ,double);
        double perimeter(double,double,double );
        double area(double,double,double  );
        int type(double,double,double  );
        void display();
}oj_a,oj_b;
double triangle::init(double a , double b, double c)
{
    if(a+b>c && a+c>b && b+c>a)
        return a,b,c;
    else
        throw a;
}
double triangle::perimeter(double a, double b, double c)
{
    double perimeter1;
    perimeter1 = a+b+c;
    return perimeter1;
}
double triangle::area(double a,double b,double c)
{
    double p,s;
    p = (a+b+c)/2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));

    return s;
}
int triangle::type(double ,double , double  )
{
    if((pow(a,2)+pow(b,2))==pow(c,2)||(pow(b,2)+pow(c,2))==pow(a,2)||(pow(a,2)+pow(c,2))==pow(b,2))
        return 1;
    else if((pow(a,2)+pow(b,2))>pow(c,2)||(pow(b,2)+pow(c,2))>pow(a,2)||(pow(a,2)+pow(c,2))>pow(b,2))
        return 2;
    else
        return 3;
}
void triangle::display()
{
    cout<<"����oj_a�ĵ�ַΪ��"<<&oj_a<<endl;
    cout<<"����oj_b�ĵ�ַΪ��"<<&oj_b<<endl;
    cout<<"����oj_a��x,y,z�ĵ�ַ�ֲ�Ϊ��"<<endl<<&this->a<<endl<<&this->b<<endl<<&this->c;
}
int main()
{
    try
    {
        double x,y,z;
        cout<<"�����������ε����ߣ�"<<endl;
        cin>>x>>y>>z;
        oj_a.init(x,y,z);
        cout<<"�������ε��ܳ�Ϊ��"<<oj_a.perimeter(x,y,z)<<endl;
        cout<<"�������ε����Ϊ��"<<oj_a.area(x,y,z)<<endl;

        if (oj_a.type(x,y,z)==1)
            cout<<"�������ε������ǣ�ֱ��������"<<endl;
        else if(oj_a.type(x,y,z)==2)
            cout<<"�������ε������ǣ��۽�������"<<endl;
        else
            cout<<"�������ε������ǣ����������"<<endl;

        cout<<"��ռ�ڴ��СΪ��"<<endl<< sizeof(oj_a)<<endl<< sizeof(oj_b)<<endl<< sizeof(x)<<endl;

        oj_a.display();

        return 0;

    }
    catch(double)
    {
        cout<<"�������߲��ܹ���������"<<endl;
    }
}

