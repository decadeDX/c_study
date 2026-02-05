#include <iostream>
using namespace std;


//作业1：判断ascii码是回文
bool isTrue(char* str, int size) {
	if (size <= 1) {
		return true;
	}
	char* left = str;
	char* right = str + size - 1;
	while (left < right) {
		if (*left != *right) {
			return false;
		}
		left++;
		right--;
	}
	return true;
}

//作业2：判断输入中文是回文
//GBK字符，中文占二字节 
bool isTrueChinese(char* str, int size) {
	if (size <= 0) return true;
	if (size == 2) return true;
	if (size % 2 != 0) return false;
	char* left = str;
	char* right = str + size - 2;
	while (left < right) {
		if (*left != *right || *(left + 1) != *(right + 1)){
			return false;
		}
		left += 2;
		right -= 2;
	}
	return true;
}

int main() {
	//作业1输入：
	//int n;
	//cin >> n;
	//char* s = new char[n];
	//for (int i = 0; i < n; i++) {
	//	cin >> s[i];
	//}
	//cout << (isTrue(s, n) ? "是回文" : "不是回文");


	//作业二输入：
	cout << "请输入中文字符串" << endl;
	char str[100] = { 0 };
	//fgets(str,100,stdin);//这里会将换行符也读入，所以需要进行处理
	//int n = strlen(str);
	//if (n > 0 && str[n - 1] == '\n') {
	//	str[n - 1] = '\0';
	//	n--;
	//}
	cin >> str;
	int n = strlen(str);
	cout << (isTrueChinese(str, n) ? "是中文回文" : "不是中文回文");
}