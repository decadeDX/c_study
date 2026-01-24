#include <stdio.h>
#include <stdlib.h>

int fun1(int num) {
	int result = 1;
	for (int i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}

int fun2(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += fun1(i);
		//printf("%d\n", fun1(i));
	}
	return sum;
}

//练习2：用递归方法来实现阶乘
int fun3(int num) {
	if (num > 1) {
		return  fun3(num - 1) * num;
	}
	else {
		return 1;
	}
}

void Print(int num) {
	if (num > 0) {
		Print(num - 1);
		printf("%d\n", num);

	}
	return;
}

int main() {
	//int number = 0;
	//scanf("%d", &number);
	//printf("%d", fun3(number));
	Print(5);
} 