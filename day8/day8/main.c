#include <stdio.h>


#define N 15
void CaculateYH(int a[][N], int n);
void PrintYH(int a[][N], int n);

int main()
{
	//int arr[3][2] = { {1,2},{3,4},{5,6} };
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		/*printf("%d ", *(*(arr + i) + j));*/
	//		printf("%d ", *(arr[i] + j)); //arr[i]就是指针数组，里面的内容都是指针.
	//		//printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}
	//const int* p;//常量指针
	//int* const q = arr;//指针常量
	//p = arr;
	//p = arr + 1;

	//数组指针
	int a[2][3] = { {1,2,3},{4,5,6} };
	int(*p)[2][3] = &a;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			//printf("%d ", (*p)[i][j]);
			printf("%d ", *(*(*p + i) + j));
		}
		printf("\n");
	}

}

void CaculateYH(int a[][N], int n) {
	for (int i = 0; i < n; i++) {
		a[i][0] = 1;
		a[i][i] = 1;
		for (int j = 0; j <= i; j++) {
			if (i > 1) {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
}

void PrintYH(int a[][N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

