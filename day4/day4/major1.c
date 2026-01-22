#include <stdio.h>

int main() {
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);

	int num1 = a < 0 ? 0 : a;
	int num2 = b < 0 ? 0 : b;

	//统一计算low和high，无需多分支
	int low = num1 < num2 ? num1 : num2;
	int high = num1 > num2 ? num1 : num2;

	//判断修正后的区间是否无效
	if (low == 0 && high == 0) {
		printf("未找到回文数\n");
		return 0;
	}
	int count = 0;
	int found = 0;
	for (int i = low; i <= high; i++) {
		int sum = 0;
		int temp = i;
		while (temp){
			sum = sum * 10 + temp % 10;
			temp /= 10;
		}
		if (sum == i) {
			count++;
			found = 1;
			if (count <= 5) {
				printf("%d ", i);
			}

		}
	}
	if (!found) {
		printf("未找到回文数\n");
	}
	return 0;
}