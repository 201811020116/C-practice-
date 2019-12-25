#include <iostream>
#include <cstring>
using namespace std;


class Vect{
private:
    int x,y;
public:
    Vect(int a=0,int b=0);
    Vect &operator +=(Vect );
    friend Vect &operator -=(Vect &v1,Vect &v2);
    void display(Vect &);
};

Vect::Vect(int a, int b):x(a),y(b) {
    cout <<"构造函数被调用。"<<endl;
}

Vect &Vect::operator+=(Vect v) {
    x+=v.x;
    y+=v.y;
    return *this;
}

Vect &operator-=(Vect &v1, Vect &v2) {
    v1.x=v2.x;
    v1.y=v2.y;
    return v1;
}

void Vect::display(Vect & v3) {

    cout<<"向量的坐标为："<<"("<<v3.x<<","<<v3.y<<")"<<endl;
}

int main(){
    Vect v1(5,6);
    Vect v2(2,3),v3;
    v3=v1;
    cout<<"v1" ;v1.display(v1);
    cout<<"v2";v2.display(v2);
    cout<<"v3";v3.display(v3);
    v1.operator+=(v2);
    cout<<"v1";v1.display(v1);
    operator-=(v3,v2);
    cout<<"v3";v3.display(v3);
    return 0;
}