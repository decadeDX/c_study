#include <stdio.h>

int main() {
	for (int i = 100; i < 1000; i++) {
		int sum = 0;
		int number = 0;
		int temp = i;
		while (temp) {
			number = temp % 10;
			sum += number * number * number;
			temp /= 10;
		}
		if (sum == i) {
			printf("%d是一个水仙数\n", i);
		}
	}
}