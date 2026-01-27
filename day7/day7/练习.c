#include <stdio.h>
#include <stdlib.h>


//练习1：定义函数，
int opSwitch(int a, int b, char op, int* pres) {
	switch (op) {
		case ('+'):
			*pres = a + b;
			return 0;
		case ('-'):
			*pres = a - b;
			return 0;
		case ('*'):
			*pres = a * b;
			return 0;
		case ('/'):
			*pres = a / b;
			return 0;
		case ('%'):
			*pres = a % b;
			return 0;
		default:
			printf("OP IS ERREO");
			return -1;
	}
}

int*  getNum() {
	int number = 100;
	int* p = &number;
	return p;
}

int** generateMatrix(int n) {
	//*returnSize = n;
	//*returnColumnSizes = (int*)malloc(sizeof(int) * n);
	int** ans = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		//(*returnColumnSizes)[i] = n;
		if (ans) {
			ans[i] = (int *)calloc(n, sizeof(int));
		}
	}
	int x = 0, y = 0;
	int total = 1;
	while (total <= n * n) {
		while (y < n && ans[x][y + 1] == 0) {
			ans[x][y++] = total++;
		}
		while (x < n && ans[x + 1][y] == 0) {
			ans[x++][y] = total++;
		}
		while (x - 1 > 1 && ans[x - 1][y] == 0) {
			ans[x][y--] = total++;
		}
		while (y - 1 > 1 && ans[x][y - 1] == 0) {
			ans[x--][y] = total++;
		}
	}
	return ans;
}

int main() {
	//int a, b;
	//char op;
	//scanf("%d%c%d", &a, &op, &b);
	//int res;
	//opSwitch(a,b,op, &res);
	//printf("%d", res);


	//练习2:用指针遍历数组
	//int arr[] = { 1,2,3,4,5 };
	//int* p = arr;
	//for (int i = 0; i < 5; i++) {
	//	printf("%d", *(p + i));
	//}

	//常量指针
	//可以改变指向，但不能改变值
	//int a = 100, b = 200;
	//const int* ptr = &a;
	//ptr = &b;
	//printf("%d", *ptr);

	//指针常量
	//可以改变值，但不能改变指向
	//int* const p1 = &a;
	//*p1 = 300;
	//printf("%d\t%d", *p1, a);
	//

	//int* res = getNum();
	//printf("*res = %d\n", *res);
	//printf("*res = %d\n", *res);
	//printf("*res = %d\n", *res);
	//printf("*res = %d\n", *res);
	//printf("*res = %d\n", *res);
	int** arr = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++) {
		arr[i] = (int *)calloc(3, sizeof(int));
	}
	int* col = (int*)calloc(3 , sizeof(int));
	arr = generateMatrix(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
}