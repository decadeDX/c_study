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
	for (int i = 0; i < n - 1; i++) {
		int min = a[i];
		int m_index = i;
		int temp = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < min) {
				min = a[j];
				m_index = j;
			}
		}
		temp = a[i];
		a[i] = min;
		a[m_index] = temp;
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}