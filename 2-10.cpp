//2-10.cpp�����õ�������ʹ��ʾ��
#include <iostream>
using namespace std;
int x=5,y=10;
int &r;                                     	//����һ������r,��δͬʱ������г�ʼ�������򱨴�
void print()                                    	//����һ��ר����������ĺ���
{    cout<<"x="<<x<<" y="<<y<<" r="<<r<<endl ;  	//���x��y��r��ֵ
    cout<<"Address of x "<<&x<<endl;        	//�������x���ڴ��ַ
    cout<<"Address of y "<<&y<<endl;          	//�������y���ڴ��ַ
    cout<<"Address of r "<<&r<<endl ;       		//�������r���ڴ��ַ
}
int main()
{
    print();                                   	//��1�ε����������
    r=y ;
    y=100 ;
    print() ;                                  	//�ٴε����������
    x=200;
    print() ;                                  	//�ٴε����������
    return 0;
}