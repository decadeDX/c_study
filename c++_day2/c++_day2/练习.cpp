#include <iostream>

using namespace std;

int main() {
	/*int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}
	cout << sum;*/
	/*int n;
	do {
		cin >> n;
		if (n % 2 == 0)
		{
			cout << "是偶数" << endl;
		} 
		else
		{
			cout << "是奇数" << endl;
		}
	} while (n != 0);*/

	//九九乘法表
	for (int i = 1; i <= 9; i++) 
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << '*' << i << '=' << (i * j) << ' ';
		}
		cout << endl;
	}
	return 0;
}

