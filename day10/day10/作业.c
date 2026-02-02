#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//增添乘除
void test9(char* s) {
	double sum = 0;//存最终结果
	double temp = 0;//存乘除结果或者符号前的数
	int i = 0;
	char op = '+';//默认开始为加法
	while (s[i] != '\0') {
		//负数标志,每次循环要置0	
		int is_neg = 0;

		//判断是否是负数
		if (s[i] == '-' && (i == 0 || !isdigit(s[i - 1]))) {//这里或的先后顺序不能变，不然会出现越界情况
			is_neg = 1;
			i++;
		}
		//取数
		if (isdigit(s[i])) {
			int current_num = 0;
			while (s[i] != '\0' && isdigit(s[i])) {
				current_num = current_num * 10 + s[i] - '0';
				i++;
			}
			if (is_neg) {
				current_num = -current_num;
			}
			switch (op) {
				case '+':
					sum += temp;
					temp = current_num;
					break;
				case '-':
					sum += temp;
					temp = -current_num;
					break;
				case '*':
					temp *= current_num;
					break;
				case '/':
					temp = (current_num != 0) ? (temp / current_num) : 0;
					break;
			}
			
		}
		else {
			if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
				op = s[i];
			}
			i++;
		}
	}
	sum += temp;//考虑到最后符号为乘除时，没有更新sum的情况。
	printf("%lf\n", sum);
}

int main() {
	char ch;
	char* s2 = NULL;  // 初始化为 NULL，避免野指针
	int i = 0;

	s2 = (char*)malloc(32 * sizeof(char));
	while ((ch = getchar()) != '\n') {

		if (i >= (32 * (i / 32 + 1)) - 1) {
			// 扩容为原来的 2 倍
			char* temp = (char*)realloc(s2, (i / 32 + 1) * 64 * sizeof(char));
			if (temp == NULL) {
				printf("内存扩容失败！\n");
				free(s2);  // 释放已分配的内存，避免内存泄漏
				return 1;
			}
			s2 = temp;
		}
		s2[i] = ch;
		i++;
	}
	s2[i] = '\0';

	test9(s2);

	free(s2);
	s2 = NULL;
	return 0;
}
