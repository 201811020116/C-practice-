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
    cout<<"对象oj_a的地址为："<<&oj_a<<endl;
    cout<<"对象oj_b的地址为："<<&oj_b<<endl;
    cout<<"对象oj_a中x,y,z的地址分布为："<<endl<<&this->a<<endl<<&this->b<<endl<<&this->c;
}
int main()
{
    try
    {
        double x,y,z;
        cout<<"请输入三角形的三边："<<endl;
        cin>>x>>y>>z;
        oj_a.init(x,y,z);
        cout<<"该三角形的周长为："<<oj_a.perimeter(x,y,z)<<endl;
        cout<<"该三角形的面积为："<<oj_a.area(x,y,z)<<endl;

        if (oj_a.type(x,y,z)==1)
            cout<<"该三角形的类型是：直角三角形"<<endl;
        else if(oj_a.type(x,y,z)==2)
            cout<<"该三角形的类型是：钝角三角形"<<endl;
        else
            cout<<"该三角形的类型是：锐角三角形"<<endl;

        cout<<"所占内存大小为："<<endl<< sizeof(oj_a)<<endl<< sizeof(oj_b)<<endl<< sizeof(x)<<endl;

        oj_a.display();

        return 0;

    }
    catch(double)
    {
        cout<<"该三条边不能构成三角形"<<endl;
    }
}

