#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int main() {
	srand((unsigned int)time(NULL));
	int n;
	scanf("%d", &n);
	int a[MAX] = { 0 };
	for (int i = 0; i < n; i++) {
		a[i] = rand();
		printf("%d ", a[i]);
	}
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
} 
// 3 1 2   一趟 1 2 3 交换两次 二趟 