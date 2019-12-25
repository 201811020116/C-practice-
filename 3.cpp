#include <iostream>
using namespace std;

class point{
private:
    float x,y;
public:
    point(float xx=00,float yy=0){
        x=xx;
        y=yy;
    }
    float get_x(){
        return x;
    };
    float get_y(){
        return y;
    };
    point operator++();
    point operator--();
};
point point::operator++() {
    if(x<640){
        ++x;
    }
    if(y<480){
        ++y;
    }
    return *this;
}
point point::operator--() {
    if(x>0){
        --x;
    }
    if(y>0){
        --y;
    }
    return *this;
}

int main(){
    point p1(10,10),p2(200,200);
    for(int i=0;i<5;i++){
        cout<<"p1:x="<<p1.get_x()<<"  y="<<p1.get_y()<<endl;
        ++p1;
    }
    for(int i=0;i<5;i++){
        cout<<"p2:x="<<p2.get_x()<<"   y="<<p2.get_y()<<endl;
        --p2;
    }
    return 0;
}
