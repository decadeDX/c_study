#include <iostream>

using namespace std;

int main() 
{
	//收银小程序,单价，数目，金额，输出找零
	//double price;
	//int num;
	//double pay;
	//cout << "单价是：" << endl;
	//cin >> price;
	//cout << "数目是：" << endl;
	//cin >> num;
	//cout << "金额是：" << endl;
	//cin >> pay;
	//double change = pay - price * num;
	//cout << "找零: " << change << endl;


	//练习2：
	int num;
	/*int res = 0;
	cin >> num;
	int tmp = 0;
	tmp = num % 10;
	num /= 10;
	res = res * 10 + tmp;
	tmp = num % 10;
	num /= 10;
	res = res * 10 + tmp;
	tmp = num % 10;
	num /= 10;
	res = res * 10 + tmp;
	cout << res << endl;*/

	int num1, num2, num3;
	cin >> num;
	num1 = num % 10;
	num2 = num % 100 / 10;
	num3 = num % 1000 / 100;
	int res = num1 * 100 + num2 * 10 + num3;
	cout << res << endl;
	return 0;
}
