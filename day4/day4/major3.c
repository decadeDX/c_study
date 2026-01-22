#include <stdio.h>

int main() {
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	if (a == b || a < 0 || b < 0) {
		printf("输入错误");
		return -1;
	}
	int low = a < b ? a : b;
	int high = a > b ? a : b;

	//方法一

	//int found = 0;//是否找到
	//for (int i = low; i <= high; i++) {
	//	int target = i;//
	//	int base = target % 10;//基准
	//	int is_allsame = 1;//是否都相同，初始为真

	//	//判断是否各位相同
	//	while (target) {
	//		int current = target % 10;//当前位
	//		target /= 10;
	//		if (current != base) {
	//			is_allsame = 0;//有不同直接结束循环
	//			break;
	//		}
	//	}
	//	if (is_allsame) {
	//		printf("%d ", i);
	//		found = 1;//找到了
	//	}
	//}
	//if (!found) {
	//	printf("未找到各个位都相同的数");
	//}

	//方法二
	int found = 0;
	int count_high = 0;
	int count_low = 0;
	int l = low;
	int h = high;
	while (l) {
		l /= 10;
		count_low++;
	}
	while (h) {
		h /= 10;
		count_high++;
	}
	for (int i = 1; i < 10; i++) {
		int number = 0;
		for (int j = 1; j <= count_high; j++) {
			 number = number * 10 + i;
			 if (j >= count_low && number >= low && number <= high) {
				 printf("%d ", number);
				 found = 1;
			}
			 if (number > high) break;
		}

	}
	if(!found) {
		printf("未找到各个位都相同的数");
	}
	return 0;
}