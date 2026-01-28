#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>




//作业一
int* getSecondMax(int** arr, int row, int col) {
	//初始化最大值和次大值及其下标
	int max = arr[0][0];
	int ind_i = 0, ind_j = 0;

	int sec_max = INT_MIN;
	int sec_ind_i = 0, sec_ind_j = 0;

	int* p = (int*)calloc(6, sizeof(int));// 开辟数组，保存最大值和次大值以及其下标
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 100 + 1;
			int curr = arr[i][j];
			if (curr > max) {//更新最大值和次大值
				sec_max = max;
				sec_ind_i = ind_i;
				sec_ind_j = ind_j;
				max = curr;
				ind_i = i;
				ind_j = j;
			}
			else if (curr > sec_max && curr < max) {//更新次大值
				sec_max = curr;
				sec_ind_i = i;
				sec_ind_j = j;
			}
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	p[0] = max; p[1] = ind_i; p[2] = ind_j;
	p[3] = sec_max; p[4] = sec_ind_i; p[5] = sec_ind_j;
	return p;
}

//作业二
double* getAvg(int** arr, int n, int low, int high) {

	double* res = (double*)calloc(n, sizeof(double));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % (high - low + 1) + low;
		}
	}
	for (int i = 0; i < n; i++) {
		int min = INT_MAX, max = arr[i][0];
		for (int j = 0; j < 10; j++) {
			if (arr[i][j]> max) {
				max = arr[i][j];
			}
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
			res[i] += arr[i][j];
			printf("%d ", arr[i][j]);
		}
		res[i] = (res[i] - min - max) / 8;
		printf("\n");
	}
	return res;
}

int main() {

	srand((unsigned int)time(NULL));

	//作业1
	int** arr1 = (int**)calloc(3, sizeof(int*));
	for (int i = 0; i < 3; i++) {
		arr1[i] = (int*)calloc(4, sizeof(int));
	}
	int* res1 = getSecondMax(arr1,3,4);
	printf("次大值是%d，行下标是%d,列下标是%d\n", res1[3], res1[4], res1[5]);

	//释放空间
	free(res1);
	for (int i = 0; i < 3; i++) free(arr1[i]);
	free(arr1);
	

	//作业2
	printf("输入学生人数\n");
	int n;
	scanf("%d", &n);
	printf("输入分数范围\n");
	int l, h;
	scanf("%d%d", &l, &h);
	int** arr2 = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr2[i] = (int*)calloc(10, sizeof(int));
	}
	double* res2 = getAvg(arr2, n, l, h);
	for (int i = 0; i < n; i++) {
		printf("%lf ", res2[i]);
	}

	//释放空间
	free(res2);
	for (int i = 0; i < n; i++) free(arr2[i]);
	free(arr2);
	return 0;

}