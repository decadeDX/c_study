#include <iostream>
// 使用std命名空间里面的自带对象
using namespace std;

void test01()
{
	cout << 123 << "abc" << endl;
	cout << "请输入年龄：";
	int age;
	cin >> age;
	if (age >= 18)
	{
		cout << "可以上网" << endl;
	}
	else
	{
		cout << "不能上网" << endl;
	}
}

int test02(int a, int b)
{
	return  a > b ? a : b;
}


void test03()
{
	int num1, num2;
	cin >> num1 >> num2;
	int res = test02(num1, num2);
	cout << "max = " << res << endl;
}

void test04()
{
	// 分配单个空间
	int* p1 = new int(100);
	*p1 = 2000;
	cout << "*p1 = " << *p1 << endl;
	//释放空间
	delete p1;
}

void test05()
{
	// 分配多个连续的空间
	// 开辟连续的10个int类型的空间
	int* p = new int[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		p[i] = 10 + i;
	}

	for (i = 0; i < 10; i++)
	{
		cout << p[i] << "\t";
	}
	cout << endl;

	// 释放空间
	delete[] p;
}

// 定义函数对数组进行翻转，要求不改变原数组的顺序，通过函数可以获得翻转之后的新数组。
int* reverse(int* p, int len)
{
	// 静态数组的生命周期会跟着函数的结束而结束，所以返回数组并不能获取整个数组元素
	// int newArr[5];
	// 动态的空间不会随着函数的结束而释放，手动销毁才会被释放
	int* newArr = new int[len];
	int i;
	int j = 0;
	for (i = len - 1; i >= 0; i--)
	{
		newArr[j] = p[i];
		j++;
	}
	return newArr;
}
int main()
{
	int arr[5] = { 10,20,30,40,50 };
	int * ap = reverse(arr, 5);
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << ap[i] << "\t";
	}
	cout << endl;
	// 使用完毕之后要进行释放
	delete[] ap;
	return 0;
}