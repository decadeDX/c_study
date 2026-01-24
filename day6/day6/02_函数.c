#include <stdio.h>
#include <string.h>
#include <time.h>

//#define Max 100

int find_min(int a, int b, int c) {
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int fun1(int x, int n) {
	if (n < 0) {
		printf("输入错误\n");
		return -1;
	}
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

void bubbleSort(int a[], int n) {
	int temp;
	int exchange = 0;
	for (int i = 0; i < n - 1; i++) {
		exchange = 0;
		for (int j = 0; j < n - i; j++) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				exchange = 1;
			}
		}
		if (!exchange) {
			break;
		}
	}
}


#define Max 128

//int lengthOfLongestSubstring(char* s) {
//	//遍历，双重循环，外部循环次数，内部有重复退出并记录当前字符串长度，
//	//和长度值进行比较，如果比记录值大，更新
//	//
//	int len = strlen(s);
//	if (!len) return 0; //为空返回0
//	int max = 1;//初始最大为1
//	for (int i = 0; i < len - 1; i++) {
//		int a[Max] = { 0 }; //保存访问位
//		int current_len = 1;//初始值为1
//		for (int j = i + 1; j < len; j++) {
//			if (s[j] != s[i] && a[s[j]] < 1) {
//				current_len++;
//				a[s[j]]++;
//				if (current_len > max) {
//					max = current_len;
//				}
//			}
//			else {
//				break;
//			}
//		}
//	}
//	return max;
//}


//优化,中间有不需要再遍历的情况，可以跳过
int lengthOfLongestSubstring(char* s) {
	//遍历，双重循环，外部循环次数，内部有重复退出并记录当前字符串长度，
	//和长度值进行比较，如果比记录值大，更新
	//
	int len = strlen(s);
	if (!len) return 0; //为空返回0
	int start = 0, end = 0, max = 0, current_len = 0;
	while (end < len) {
		char tmp = s[end];
		for (int i = start; i < end; i++) {
			if (tmp == s[i]) {
				start = i + 1;
				current_len = end - start;
				break;
			}
		}
		end++;
		current_len++;
		max = max < current_len ? current_len : max;
	}
	return max;
}
// 0 1 2 3 4 5 6 7 8 9
// 

void printPrime(int start, int end) {
	
	for (int i = start; i <= end; i++) {
		int flag = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("%d ", i);
		}

	}
}

int main() {
	//练习1：定义一个函数，输出三个数中的最小值
	//int a, b, c;
	//scanf("%d%d%d", &a, &b, &c);
	//printf("%d\n",find_min(a,b,c));

	//练习2：计算x的n次方
	//int x, n;
	//scanf("%d%d", &x, &n);
	//printf("%d\n", fun1(x, n));
	//return 0;

	//练习3:将数组传入，并排序，然后输出
	//int n = 0;
	//scanf("%d", &n);
	//int a[Max];
	//for (int i = 0; i < n; i++) {
	//	scanf("%d", &a[i]);
	//}
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", a[i]);
	//}
	//printf("\n");
	//bubbleSort(a, n);
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", a[i]);
	//}

	char ch;
	int i = 0;
	char s[] = { "pwcwcb" };
	printf("%d\n", lengthOfLongestSubstring(s));

	//练习4：输入范围，打印出范围中的素数
	//int a, b;
	//scanf("%d%d", &a, &b);
	//printPrime(a, b);

}