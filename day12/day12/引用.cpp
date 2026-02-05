#include <iostream>
using namespace std;

//值传递
void swap1(int a, int b) {
	cout << "交换前 a = " << a << "\tb = " << b << endl;
	int tmp = a;
	a = b;
	b = tmp;
	cout << "交换后 a = " << a << "\tb = " << b << endl;
}

//地址传递
void swap2(int* a, int* b) {
	cout << "交换前 a = " << *a << "\tb = " << *b << endl;
	int tmp = *a;
	*a = *b;
	*b = tmp;
	cout << "交换后 a = " << *a << "\tb = " << *b << endl;
}


//引用
void swap3(int& a, int& b) {
	cout << "交换前 a = " << a << "\tb = " << b << endl;
	int tmp = a;
	a = b;
	b = tmp;
	cout << "交换后 a = " << a << "\tb = " << b << endl;
}

//编写一个将两个字符串拼接起来的函数
//void stringCat(char* s1, char* s2) {
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	int len = len1 + len2;
//	char* s3 = new char[len + 1];
//	int i = 0;
//	for (; i < len; i++) {
//		if (i < len1) {
//			s3[i] = s1[i];
//		}
//		else {
//			s3[i] = s2[i - len1];
//		}
//	}
//	s3[i] = '\0';
//	cout << s3;
//	delete[] s3;
//}

//编写一个将两个字符串拼接起来的函数
void stringCat(char* s1, char* s2) {
	char* p = s1 + strlen(s1);
	int i = 0;
	int len = strlen(s2);
	/*while (i < len) {
		*s3 = *s2;
		s3++;
		s2++;
		i++;
	}*/

	while (*s2 != '\0') {
		*p = *s2;
		p++;
		s2++;
	}
	*p = '\0';
	cout << s1;
	
}

//函数重载
int add(int a, int b) {
	return a + b;
}
 
// 练习：求x的n次方，默认计算10的2次方
void test1(int x = 10, int n = 2) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= x;
	}
	cout << res;
}

int main() {
	//int a = 100;
	//int& b = a; 
	//cout << a << b << endl;
	////引用和指针常量
	//int* const p = &a;
	//b = 1000;
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "*p = " << *p << endl;
	//int x = 10, y = 20;
	//swap1(x, y);
	//swap2(&x, &y);
	//swap3(x, y);
	//char s1[20] = "sadfasdf";
	//char s2[20] = "123456578";
	//stringCat(s1, s2);
	test1(5,2);
}