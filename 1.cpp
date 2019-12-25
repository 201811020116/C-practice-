#include <iostream>
using namespace std;

class base{
public:
    base();

    virtual void f();
};
class derived:public base{
public:
    derived ();
    void f();


};
base::base(){
    cout<<"调用base构造函数"<<endl;
    f();
}
void base::f() {
    cout<<"base类f()被调用"<<endl;
}
derived::derived() {
    cout<<"调用derived 构造函数"<<endl;
    f();
}
void derived::f() {
    cout<<"derived 类f()被调用"<<endl;
}

int main(){
    derived d;
    return 0;
}