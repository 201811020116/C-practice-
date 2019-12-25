#include <iostream>
using namespace std;

#include <math.h>

class Triangle

{

private:

	double a, b, c;

public:

    Triangle(){ }

    Triangle(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;

        while (( a + b <= c) ||  (a + c <= b) || (b + c <= a))
        {
            cout << "���������������α߳���";
            cin >> a >> b >> c;
        }
    }
    Triangle(const Triangle &other)
    {
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
    }
    ~Triangle() {}

    double perimeter()
    {
        return a + b + c;
    }
    double area()
    {
        double p = 0.5*perimeter();

        double s = sqrt(p *(p - a) *(p - b)* (p - c)) ;

        return s ;
    }
    double operator+(Triangle &r)
    {

	    double sum = 0.0;

	    sum = this->area() + r.area();

	    return sum;

	}
    Triangle& operator=(Triangle &r)
    {
	    this->a = r.a;

	    this->b = r.b;

	    this->c = r.c;

	    return  *this ;

	}
	friend ostream& operator<<(ostream &out, Triangle &t);
	};

	ostream& operator<<(ostream &out, Triangle &t)

	{
	out << "�߳�Ϊ: " << t.a <<" "<< t.b << " " << t.c << endl;

	out << "�ܳ�Ϊ:" << t.perimeter()<<endl;

	out << "���Ϊ:" << t.area()<< endl;

	return out;

	}
	int main()
	{
	Triangle A(3,4,5) ;

	Triangle B = A;

	Triangle C;

	C = B;

    double sum = A + B;

	cout << "�������֮��: A + B = " << sum << endl;

	cout << A<<endl;

	cout << B<<endl;

	cout << C<<endl;

	return 0;
	}
