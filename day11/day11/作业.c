#include <stdio.h>
#include <stdlib.h>


void test1() {
	static int num = 1;
	int sum = 1;
	for (int i = 1; i <= num; i++) {
		sum *= i;
	}
	printf("%d\n", sum);
	num++;
}

int main() {
	int i = 0;
	while (i < 10) {
		test1();
		i++;
	}
}