#include <iostream>
using namespace std;

int main()
{
	while (1) {
	
		float a, b, c, d, x1, x2; //定义变量

		cout << "请输入二元一次方程的系数:" << endl;

		cin >> a >> b >> c; //输入系数

		d = b * b - 4 * a * c; //计算根的判别式

		/* 讨论方程组有无解 */
		if (d < 0)              //d<0时方程组无解
		{
			cout << "该方程组无解." << endl;
		}
		else if (d == 0)         //d==0时方程组有两个同解
		{
			x1 = x2 = (-1 * b + sqrt(d)) / (2 * a);
			cout << "该方程组的解为: x1 = x2 = " << x1 << endl;
		}
		else                   //d>0时方程组有两个异解
		{
			x1 = (-1 * b + sqrt(d)) / (2 * a);
			x2 = (-1 * b - sqrt(d)) / (2 * a);
			cout << "该方程组的解为:x1 = " << x1 << "x2 = "<< x2 << endl;
		}

		cout << "继续求解请按y,退出请按n" << endl;
		getchar();
		if (getchar() == 'n') {
			break;
		}
	}
}
