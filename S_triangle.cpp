#include <iostream>
using namespace std;


int main() {

	float a, b, c, d, s;     // �������߱߳������

	while (1) {
		cout << "���������߱߳�:" << endl;

		cin >> a >> b >> c;               // ����߳�

		if (a + b <= c || a + c <= b || b + c <= a) // �ж������ܷ񹹳�������
		{
			cout << "�����߹����������� " << endl;
		}
		else {                                      // ����������,������������
			d = (a + b + c) / 2;

			s = sqrt(d * (d - a) * (d - b) * (d - c));

			cout << "�����ε����Ϊ: s = " << s << endl;
		}

		cout << "��������밴y,�˳��밴n" << endl;  
		getchar();
		if (getchar() == 'n') {                    // �˳�ѭ��
			break;
		}
	}
}
