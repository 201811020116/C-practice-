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
            cout<< "请输入学生姓名,年龄,分数:"<<endl;
            cin>>name >>age>>score;
            cout<<"该同学的姓名，年龄，百分制成绩为："<<name <<", "<<age<<", "<<checkAgeScore(age,score)<<endl;
        }
        catch(int )
        {
            cout<<"输入年龄异常"<<endl;
        }
        catch(float )
        {
            cout<<"输入分数异常"<<endl;
        }
        cout<<"退出请按n，继续查询请按任意键：";
        getchar();
        if(getchar()=='n')
            break;
    }
}
