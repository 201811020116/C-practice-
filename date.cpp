#include <iostream>
using namespace std;

int main() {

	int year, month, day; // ����������
	int week = 1;  //��ʼ���ܴ���
	char i  ;
	int count[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //���������������������ɵ�����
	
	while (1) {               // ����ѭ��

		cout << "��������,��,��(��ʽ:2019-9-21):" << endl;

		cin >> year >> i >> month >> i >> day; //д��������

		if (month <= 0 || year <= 0 || day <= 0 || month > 12 || day > 31)  // �ų����Ϸ������
		{
			cout<< "���벻�Ϸ�!" << endl;
		}
		else {                                                //�ж�����ƽ��
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
			{
				for (int i = 0; i < month - 1; i++)        //����������ĵڼ��� ,�ڼ���
				{
					day += count[i];
					week = day / 7;
				}
			}
			else
			{                                      //  ������ƽ��ĵڼ��� ,�ڼ���
				count[1] = 28;
				for (int i = 0; i < month - 1; i++)
				{
					day += count[i];
					week = day / 7;
				}
			}
			cout << "��һ���Ǹ���ĵ�" << day << "��" << endl;
			cout << "��һ���Ǹ���ĵ�" << week << "�� " << endl;
		}
		cout << "������ѯ�밴y,�˳��밴n" << endl;
		getchar();
		if (getchar() == 'n'){
			break;
		}
	}	
}