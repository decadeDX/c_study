#include <stdio.h>
#include <stdlib.h>


void init(int arr[], int arrsize) {
	for (int i = 0; i < arrsize; i++) {
		scanf("%d", &arr[i]);
	}
	return;
}

void empty(int arr[], int arrsize) {
	for (int i = 0; i < arrsize; i++) {
		arr[i] = 0;
	}
}

void reserve(int arr[], int arrsize) {
	for (int i = 0,j = arrsize - 1; i < j; i++, j--) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	return;
}

int getSum(int arr[], int arrsize) {
	int sum = 0;
	for (int i = 0; i < arrsize; i++) {
		sum += arr[i];
	}
	return sum;
}

double getAvg(int arr[], int arrsize) {
	float avg = 0;
	avg = (double)getSum(arr, arrsize) / (double)arrsize;
	return avg;
}


void addNum(int arr[], int arrsize, int num) {
	for (int i = 0; i < arrsize; i++) {
		arr[i] += num;
	}
	return;
}

void display(int arr[], int arrsize) {
	for (int i = 0; i < arrsize; i++) {
		printf("%d ", arr[i]);
	}
	return;
}

int main() {
	int n,num;
	scanf("%d%d", &n, &num);
	int a[100];
	init(a, n);
	display(a, n);
	printf("\n");
	reserve(a, n);
	display(a, n);
	printf("\n");
	printf("%d\n", getSum(a, n));
	printf("%f\n", getAvg(a, n));
	addNum(a, n, num);
	display(a, n);
	printf("\n");
	empty(a, n);
	display(a, n);
	printf("\n");

}