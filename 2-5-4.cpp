#include <iostream>
using namespace std;
float checkAgeScore(int age,float score)
{
    if (age<16||age>25)
        throw age;
    else if(score<0||score >5)
        throw score;
    else
        score = score *20;
        return score;
}
int main()
{
    char name[10] ;
    int age;
    float score;
    while(1){
        try
        {
            cout<< "������ѧ������,����,����:"<<endl;
            cin>>name >>age>>score;
            cout<<"��ͬѧ�����������䣬�ٷ��Ƴɼ�Ϊ��"<<name <<", "<<age<<", "<<checkAgeScore(age,score)<<endl;
        }
        catch(int )
        {
            cout<<"���������쳣"<<endl;
        }
        catch(float )
        {
            cout<<"��������쳣"<<endl;
        }
        cout<<"�˳��밴n��������ѯ�밴�������";
        getchar();
        if(getchar()=='n')
            break;
    }
}
