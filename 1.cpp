#include <iostream>
using namespace std;

int main()
{
	while (1) {
	
		float a, b, c, d, x1, x2; //�������

		cout << "�������Ԫһ�η��̵�ϵ��:" << endl;

		cin >> a >> b >> c; //����ϵ��

		d = b * b - 4 * a * c; //��������б�ʽ

		/* ���۷��������޽� */
		if (d < 0)              //d<0ʱ�������޽�
		{
			cout << "�÷������޽�." << endl;
		}
		else if (d == 0)         //d==0ʱ������������ͬ��
		{
			x1 = x2 = (-1 * b + sqrt(d)) / (2 * a);
			cout << "�÷�����Ľ�Ϊ: x1 = x2 = " << x1 << endl;
		}
		else                   //d>0ʱ���������������
		{
			x1 = (-1 * b + sqrt(d)) / (2 * a);
			x2 = (-1 * b - sqrt(d)) / (2 * a);
			cout << "�÷�����Ľ�Ϊ:x1 = " << x1 << "x2 = "<< x2 << endl;
		}

		cout << "��������밴y,�˳��밴n" << endl;
		getchar();
		if (getchar() == 'n') {
			break;
		}
	}
}
