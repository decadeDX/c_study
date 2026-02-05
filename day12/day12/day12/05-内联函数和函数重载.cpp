#include <iostream>
using namespace std;
inline int getAdd(int a, int b)
{
	return a + b;
}

// 函数重载
void getRes(int a, int b)
{
	cout << "调用两个int类型形参的函数" << endl;
	cout << "a = " << a << "\tb = " << b << endl;
}
// 不能将函数的类型当做函数重载的依据
//int getRes(int a, int b)
//{
//	return a + b;
//}
void getRes(double a, double b)
{
	cout << "调用两个double类型形参的函数" << endl;
	cout << "a = " << a << "\tb = " << b << endl;
}

void getRes(int a, int b, int c)
{
	cout << "调用三个int类型形参的函数" << endl;
	cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;
}
int main()
{
	getRes(10, 20);
	getRes(10.11, 20.22);
	getRes(10, 20, 30);
	return 0;
}