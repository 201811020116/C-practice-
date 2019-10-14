#include <iostream>
using namespace std;
inline float circumference(float r);
inline float area(float r);
const float PI = 3.14159;
int main()
{
    float r;
    cout<<" Please input radius of the circle:\n";
    cin>>r;
    float s ,c;
    s = area(r);
    c = circumference(r);
    cout<< "the circular area is :\n"<<s<<endl;
    cout<< "the circumference is :\n"<<c<<endl;
}
float area(float r)
{
    return r * r * PI;
}
float circumference(float r)
{
    return 2* PI * r;
}