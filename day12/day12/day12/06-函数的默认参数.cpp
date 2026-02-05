#include <iostream>
using namespace std;
// 默认参数要求从右向左进行定义
// 默认参数可以在函数声明或者定义的其中一个地方说明，不能两边都有，会编译报错，一般在函数声明的时候说明
int getSum(int a, int b = 10, int c = 20);

// 练习：求x的n次方，如果没有实参，默认计算10的2次方
double power(double x = 10.0, int n = 2)
{
	int i;
	double s = 1.0;
	for (i = 0; i < n; i++)
	{
		s *= x;
	}
	return s;
}
int main()
{
	cout << power() << endl;
	cout << power(100) << endl;
	cout << power(5, 4) << endl;
	return 0;
}

int getSum(int a, int b, int c)
{
	return a + b + c;
}
