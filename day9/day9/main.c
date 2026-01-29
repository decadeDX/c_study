#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Á·Ï°£ºÊµÏÖ¼ÆËãÆ÷
int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	if (b == 0) {
		printf("³ıÊıÎªÁã");
		return -1;
	}
	return a / b;
}

int countIfArry(int* arr, int size, int (*isTrue)(int)) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (isTrue(arr[i])) {
			count++;
		}
	}
	return count;
}


int isEven(int  num) {
	return num % 2;
}

int isOushu(int num) {
	return (num + 1) % 2;
}


//Á·Ï°3
int cmp(const void* arg1, const void* arg2) {
	return *(const int*)arg1 - *(const int*)arg2;//ÉıĞòÅÅĞò
	//return *(const int*)arg2 - *(const int*)arg1;//½µĞòÅÅĞò
}

void sort() {
	int arr[6] = { 5,4,9,19,34,2 };
	qsort(arr, 6, sizeof(int), cmp);
	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
}


int main() {
	//typedef int (*Calculator)(int, int);
	//Calculator p[4] = { add,sub,mul,div };
	////¸ü·½±ãµÄ·½·¨
	////Calculator p[6] = { mul,add,NULL,sub,NULL,div };
	//int a, b;
	//char op;
	//scanf("%d%c%d", &a, &op, &b);
	//switch (op) {
	//case '+':
	//	printf("%d %c %d = %d", a, op, b, p[0](a, b));
	//	break;
	//case '-':
	//	printf("%d %c %d = %d", a, op, b, p[1](a, b));
	//	break;
	//case '*':
	//	printf("%d %c %d = %d", a, op, b, p[2](a, b));
	//	break;
	//case '/':
	//	printf("%d %c %d = %d", a, op, b, p[3](a, b));
	//	break;
	//}
	//printf("%d %c %d = %d", a, op, b, p[op - '*'](a, b));
	//srand((unsigned int)time(NULL));
	//int n;
	//scanf("%d", &n);
	//int* p = (int*)calloc(n, sizeof(int));
	//for (int i = 0, *tmp =p; i < n; tmp++, i++) {
	//	*tmp = rand() % 100 + 1;
	//	printf("%d ", *tmp);
	//}
	//printf("\n");

	//int res = countIfArry(p, n, isOushu);
	//printf("%d", res);
	//sort();
	return 0;
}