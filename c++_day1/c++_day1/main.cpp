#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//cout << "hello world!" << endl;
	//int score1 = 100;// 传统初始化方式
	//int score2(90);//对象初始化方式
	//int score3{ 80 };//统一初始化方式
	//cout << "score1 = " << score1 << endl
	//	<< "score2 = " << score2 << endl
	//	<< "score3  " << score3 << endl;
	//const char* s = "牛";
	//cout << strlen(s) << endl;
	//int n;
	//cin >> n;
	//int* arr = new int[n];

    int n;
    cin >> n;
    int* arr = new int[n];
    int* sumarr = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        sumarr[i] = sum;
    }
    int a, b, result;
    while (cin >> a >> b) {
        if (a <= 0) {
            cout << sumarr[b];
        }
        else {
            result = sumarr[b] - sumarr[a - 1];
            cout << result;
        }
        cout << endl;
    }
    return 0;

	return 0;
}