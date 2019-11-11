#include <iostream>
using namespace std;
#include <math.h>

class Point{
    double x,y;
public:
    Point();
    Point(double a, double b);
    Point(const Point& r);
    ~Point();
    double GetX();
    double GetY();
    void SetX(double ax);
    void SetY(double bx);
    void SwapAxis(double *xa, double *xb);
    friend double GetLength(Point& A,Point& B);
};
Point::Point()
{
}
Point::Point(const Point &r)
{
    cout<<"constructor 2 called.";
}
Point::Point(double a, double b)
{
    cout<<"constructor 3 called.";
}
Point::~Point()
{
}
double Point::GetX()
{
    return x;
}

double Point::GetY()
{
    return y;
}
void Point::SetX(double ax)
{
    x = ax;
}

void Point::SetY(double bx)
{
    x = bx;
}
void Point::SwapAxis(double *xa, double *xb)
{
    xa = &x;
    xb = &y;
    double *temp;
    temp = xa;
    xa = xb;
    xb = temp;
}
double GetLength(Point& A,Point& B)
{
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}

int main()
{
    Point array_stack[10];
    Point *array_heap = new Point[10];
    array_stack[2].SetX(3);
    array_stack[2].SetY(3);
    array_heap[2].SetX(0);
    array_heap[2].SetY(0);
    cout<<"array_stack[2]与array_heap[2]之间的距离为： "<<GetLength(array_stack[2],array_heap[2])<<endl;
}