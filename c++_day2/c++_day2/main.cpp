#include <iostream>
using namespace std;

int main()
{
	//练习1
	//int score;
	//cin >> score;
	//if (score < 60)
	//{
	//	cout << "E" << endl;
	//}
	//else if (score < 70)
	//{
	//	cout << "D" << endl;
	//}
	//else if (score < 80)
	//{
	//	cout << "C" << endl;
	//}
	//else if (score < 90)
	//{
	//	cout << "B" << endl;
	//}
	//else
	//{
	//	cout << "A" << endl;
	//}


	//练习2
	/*int year;
	cin >> year;
	if (year % 400 == 0) 
	{
		cout <<"是世纪闰年";
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		cout <<"是普通闰年";
	}
	else
	{	
		cout << "是平年";
	}*/


	//练习3
	/*double num;
	cin >> num;
	double tax;
	if (num <= 5000) 
	{
		tax = 0;
	} 
	else if (num <= 10000)
	{
		tax = (num - 5000) * 0.05;
	}
	else if (num <= 20000)
	{
		tax = (num - 10000) * 0.1 + 5000 * 0.05;
	}
	else if (num <= 30000)
	{
		tax = (num - 20000) * 0.15 + 5000 * 0.05 + 10000 * 0.1;
	}
	else
	{
		tax = (num - 30000) * 0.2 + 5000 * 0.05 + 10000 * 0.1 + 10000 * 0.15;
	}
	cout << tax;*/

	//练习4
	int score;
	cin >> score;
	int tmp = score / 10;
	switch (tmp) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			cout << "E" << endl;
			break;
		case 6:
			cout << "D" << endl;
			break;
		case 7:
			cout << "C" << endl;
			break;
		case 8:
			cout << "B" << endl;
			break;
		case 9:
		case 10:
			cout << "A" << endl;
			break;
		default:
			cout << "输入非法" << endl;
	}
	return 0;
}