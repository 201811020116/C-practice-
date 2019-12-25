#include <iostream>
using namespace std;

class Shapes{
public:
    virtual void display() = 0;
};

class Rectangles:public Shapes{
    
private:

    double a, b;

public:
    Rectangles(double _a, double _b)
{

    a = _a;
    
    b = _b;

}

~Rectangles(){}

void display()
{
        cout << "矩形边长为: " << a << b << endl;
        
        cout << "矩形面积为: " << a << b << endl;

}
	};

class Circles : public Shapes
{

private:

    double r;

public:

    Circles(double _r)
    {
        r = _r;
    }

~Circles(){
    }

void display(){

    cout << "圆的半径为: " <<r << endl;

    cout << "圆的面积为: " <<3.14*r* r << endl;
    
}
};

int main()
{
    Shapes *p[2]; 

    Rectangles rectangle(3, 4);

    Circles circle(2); 
    
     p[0] = &rectangle;

     p[1]=&circle;
    
     p[0]->display();

     p[1]->display();

     return 0;
}


