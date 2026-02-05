#include <iostream>
using namespace std;
// 值传递
// 数值作为函数的参数，并不会影响实参的值
// 下面的例子实际上是作为int x = a  int y = b;
void swap1(int x, int y)
{
	cout << "交换之前x = " << x << "\ty = " << y << endl;
	int temp = x;
	x = y;
	y = temp;
	cout << "交换之后x = " << x << "\ty = " << y << endl;
}

// 地址传递
// 指针变量作为函数的形参，会修改实参的值
// int* x = &a  int* y = &b;
void swap2(int* x, int* y)
{
	cout << "交换之前x = " << *x << "\ty = " << *y << endl;
	int temp = *x;
	*x = *y;
	*y = temp;
	cout << "交换之后x = " << *x << "\ty = " << *y << endl;
}

// 引用作为函数的形参，会影响实参的值
// int& x = a   int& y = b;
void swap3(int& x, int& y)
{
	cout << "交换之前x = " << x << "\ty = " << y << endl;
	int temp = x;
	x = y;
	y = temp;
	cout << "交换之后x = " << x << "\ty = " << y << endl;
}

void test01()
{
	int a = 10, b = 20;

	// 如果是值作为形参，实参可以是表达式，变量名或者直接写确定的值
	/*swap1(a, b);
	swap1(10, 20);
	swap1(a + 100, b + 200);*/
	// swap2(&a, &b);

	// 引用作为函数的形参，实参只能是变量名
	swap3(a, b);
	//swap3(10, 20);
	//swap3(a + 100, b + 200);
	cout << "a = " << a << "\tb = " << b << endl;
}

// 编写拼接两个字符串的函数（类似于strcat）
void stringCat(char* str1, char* str2)
{
	// 先将str1字符串的指针移动到结束标识的位置，保存到p中
	char* p = str1 + strlen(str1);
	while (*str2 != '\0') // 如果没有到str2的结束位置，就一直循环
	{
		*p = *str2; // 将str2对应位置的字符，赋值给p的相应位置
		p++; // 字符串1和字符串2的指针同时向后移动，直到str2所有的字符都遍历完毕
		str2++;
	}
	*p = '\0'; // 给拼接后的字符串结尾添加终止符
}
int main()
{
	char str1[100] = "abcdefg";
	char str2[100] = "ABCDEFG";
	stringCat(str1, str2);
	cout << str1 << endl;
	return 0;
}