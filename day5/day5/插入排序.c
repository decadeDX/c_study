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
	int i, j;
	for (i = 1; i < n; i++) {
		int temp = a[i];
		for (j = i; j > 0 && temp < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}