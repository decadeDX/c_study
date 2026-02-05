#include <iostream>
using namespace std;
int main()
{

	int a = 100;
	int d = 200;
	// 声明一个引用作为变量a的别名
	int& b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// 因为b是a的别名，所以在改变b的时候，实际上就是在改变a
	b = 1000;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// 引用使用的注意点
	// 1、引用必须要进行初始化
	// int& c;
	int& c = a;

	// 2、引用一旦初始化之后不可以改变（不可以作为别的变量别名使用）
	// int& c = d;
	c = d;

	// 因为c和b都是a的别名，所以动其中一个，三个都会变
	cout << "a = " << a << endl; // 200
	cout << "b = " << b << endl; // 200
	cout << "c = " << c << endl; // 200

	// 引用的本质
	// 是指针常量
	/*
		int a = 10;
		// 自动转化为int* const ref = &a; 指针常量指向不可以修改，值可以修改
		int& ref = a;
		// 如果代码发现ref是引用，就会将ref转化为*ref = 20
		ref = 20;
	*/

	// 常引用，经常会用作函数的形参，就是为了保证实参不被修改。
	// 指向和值都不可以被修改
	// const int* const c = &a;
	const int& p = a;
	// p = 1000;
	
	return 0;
}