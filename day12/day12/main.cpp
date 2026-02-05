#include <iostream>
//使用namespace空间中的自带对象
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

//定义函数对数组进行翻转，要求不改变原来数组
void reverse(int* arr, int n) {
	int* p = new int[n];
	//int p[100];
	for (int i = 0; i < n; i++) {
		p[i] = arr[n - 1 - i];
	}
	for (int i = 0; i < n; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;

	delete[] p;
	p = nullptr;
}





int main() {
	//cout << "hello world" << endl;
	//cout << "请输入年龄" << endl;
	//int age;
	//cin >> age;
	//if (age >= 18) {
	//	cout << "可以上网\n";
	//}
	//else {
	//	cout << "不可以上网\n";
	//}
	//int num1, num2;
	//cin >> num1 >> num2;
	//int res = max(num1, num2);
	//cout << "max = " << res << endl;
	int* p = new int[10];
	for (int i = 0; i < 10; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << p[i] << " ";
		p[i] = p[i] + 5;
		cout << p[i] << endl;
	}
	cout << endl;
	reverse(p, 10);
	delete[] p;
	p = nullptr;
	return 0;
}