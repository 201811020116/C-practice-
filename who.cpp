#include <iostream>
using namespace std;

class base1{
public:
     virtual void who(){
        cout<<"this is the class of base1."<<endl;
    }
};
class base2{
public:
    void who(){
        cout<<"this is the class of base2."<<endl;
    }
};

class derive: public base1, public base2{
public:
    void who(){
        cout<<"this is the class of derive"<<endl;
    }
};
int main(){
    base1 o1,*p1;
    base2 o2,*p2;
    derive o3;
    p1=&o1;
    p2=&o2;
    p1->who();
    p2->who();
    p1=&o3;
    p2=&o3;
    p1->who();
    p2->who();

    return 0;
}