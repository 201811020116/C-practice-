//2-06.cpp���������ʹȫ�ֱ�����������ȫ��������
#include <iostream>
#include <iomanip>
using namespace std;                   //ʹ��C++�ı�׼���ֿռ�
int sum=5000; 		                 //����ȫ�ֱ���sum      
int main()
{
    int sum=200;                        //�����һ���ֲ�����sum ,������Ϊ��С������������������
    int arr[3]={10,20,30};
    {                                 //һ��С�����Ŀ�ʼ
        int i,sum=0;                     //����ڶ����ֲ�����sum
        for (i=0;i<3;i++)
            sum+=arr[i];                  //��ͣ�������ڵڶ����ֲ�����sum��
        cout<<"sum="<<sum<<endl;       //����ڶ����ֲ�����sum��ֵ
        ::sum+=sum;	                   //ͨ�����������ͬ���ֲ��������������ڶ�ȫ��sum����
        cout<<"ȫ��sum="<<::sum<<endl;  //���ȫ��sum������ֵ
    }                                //С�����Ľ���
    sum*=2;                            //���ǵ�һ���ֲ�����sum��������
    cout<<"sum="<<sum<<endl;           //�����һ���ֲ�sum������ֵ

    cout<<"sum="<<sum<<endl;           //�����һ���ֲ�����sum��ֵ
    ::sum+=sum;           	          //ͨ���������ʹȫ��sum��ͬ����һ���ֲ�sum��������ɼ�
    cout<<"ȫ��sum="<<::sum<<endl;     //���ȫ��sum������ֵ
    return 0;
}

