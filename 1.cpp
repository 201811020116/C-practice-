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
    cout<<"����base���캯��"<<endl;
    f();
}
void base::f() {
    cout<<"base��f()������"<<endl;
}
derived::derived() {
    cout<<"����derived ���캯��"<<endl;
    f();
}
void derived::f() {
    cout<<"derived ��f()������"<<endl;
}

int main(){
    derived d;
    return 0;
}