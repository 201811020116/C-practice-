#include <iostream>
using  namespace std;
int main()
{
    int *a =  new int[20];
    int  i,counter1 = 0, counter2 = 0;
    cout<<"Please enter a series of values, press 'n' when you have finished typing :  "<<endl;
    while(i!=EOF)
    {
        if(cin >> i && i !=0)
        {
            if(i>0)
                counter1 ++;
            else
                counter2 ++;
        }
    }
    cout<<"���������ǣ�\n"<<counter1<<endl;
    cout<<"���������ǣ�\n"<<counter2<<endl;
    delete[]a;
    return 0;
}