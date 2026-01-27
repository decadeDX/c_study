#include <stdio.h>
#include <stdlib.h>

//练习1：交换两个变量的值,要求形参是指针
void swapNum(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}

//输入一个秒数，来获取是几天几时几分几秒

void getTime(int second) {
	int* ans = (int*)calloc(4, sizeof(int));
	if (ans) {
		ans[0] = second / (24 * 60 * 60);
		ans[1] = second / (60 * 60) % 24;
		ans[2] = second / 60 % 60;
		ans[3] = second % 60;
		printf("%d天%d时%d分%d秒", ans[0], ans[1], ans[2], ans[3]);
	}
}

int main() {
	//int a = 3, b = 6;
	//swapNum(&a, &b);
	//printf("%d\t%d", a, b);
	getTime(510000);
}