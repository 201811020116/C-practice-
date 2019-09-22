#include <iostream>
using namespace std;


int main() {

	float a, b, c, d, s;     // 定义三边边长及面积

	while (1) {
		cout << "请输入三边边长:" << endl;

		cin >> a >> b >> c;               // 输入边长

		if (a + b <= c || a + c <= b || b + c <= a) // 判断三边能否构成三角形
		{
			cout << "该三边构不成三角形 " << endl;
		}
		else {                                      // 构成三角形,求解三角形面积
			d = (a + b + c) / 2;

			s = sqrt(d * (d - a) * (d - b) * (d - c));

			cout << "三角形的面积为: s = " << s << endl;
		}

		cout << "继续求解请按y,退出请按n" << endl;  
		getchar();
		if (getchar() == 'n') {                    // 退出循环
			break;
		}
	}
}
