#include <iostream>
using namespace std;

class B
{
    int x,y;

public:
    B()
    {
        x=y=0;
        cout<<"con1\t";
    }
    B(int i)
    {
        x=i;y=0;
        cout<<"con2\t";
    }
    B(int i,int j)
    {
        x =i;y=j;
        cout<<"con3\t";
    }
    ~B()
    {
        cout<<"Des\t";
    }
};
int main()
{
    B *ptr;
    ptr = new B[3];//定义指针数组对象时，系统自动调用默认构造函数来创建并初始化对象
    ptr[0] = B();
    ptr[1] = B(1);
    ptr[2] = B(2,3); //分别对数组中的指针再次调用相应构造函数，在各自生存期结束后自动调用析构函数
    delete []ptr;  //自动调用析构函数，释放内存，调用顺序与构造函数调用顺序相反
    ptr = NULL;
    return 0;
}
