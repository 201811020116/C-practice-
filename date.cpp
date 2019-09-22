#include <iostream>
using namespace std;

int main() {

	int year, month, day; // 定义年月日
	int week = 1;  //初始化周次数
	char i  ;
	int count[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //创建由闰年各个月天数组成的数组
	
	while (1) {               // 无限循环

		cout << "请输入年,月,日(格式:2019-9-21):" << endl;

		cin >> year >> i >> month >> i >> day; //写入年月日

		if (month <= 0 || year <= 0 || day <= 0 || month > 12 || day > 31)  // 排除不合法的情况
		{
			cout<< "输入不合法!" << endl;
		}
		else {                                                //判断闰年平年
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
			{
				for (int i = 0; i < month - 1; i++)        //计算是闰年的第几天 ,第几周
				{
					day += count[i];
					week = day / 7;
				}
			}
			else
			{                                      //  计算是平年的第几天 ,第几周
				count[1] = 28;
				for (int i = 0; i < month - 1; i++)
				{
					day += count[i];
					week = day / 7;
				}
			}
			cout << "这一天是该年的第" << day << "天" << endl;
			cout << "这一周是该年的第" << week << "周 " << endl;
		}
		cout << "继续查询请按y,退出请按n" << endl;
		getchar();
		if (getchar() == 'n'){
			break;
		}
	}	
}