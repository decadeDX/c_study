#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 10000

int main() {
	srand((unsigned int)time(NULL)); //设置随机数种子

	/*                                                    作业                                                */
	//作业1
	int n;
	scanf("%d", &n);
	int a[MAX] = { 0 };
	for (int i = 0; i < n; i++) {
		a[i] = rand();
		printf("%d ", a[i]);
	}

	//选择排序 从大到小排序
	//for (int i = 0; i < n - 1; i++) {
	//	int max = a[i];
	//	int m_index = i;
	//	int temp = 0;
	//	for (int j = i + 1; j < n; j++) {
	//		if (a[j] > max) {
	//			max = a[j];
	//			m_index = j;
	//		}
	//	}
	//	temp = a[i];
	//	a[i] = max;
	//	a[m_index] = temp;
	//}
	//printf("\n");
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", a[i]);
	//}

	//冒泡排序 从大到小排
	//int a[4] = { 4,3,2,1 };
	//int temp;
	//int i;
	//for (i = 0; i < n - 1; i++) {
	//	for (int j = 0; j < n - 1 - i; j++) {
	//		if (a[j] < a[j + 1]) {
	//			temp = a[j];
	//			a[j] = a[j + 1];
	//			a[j + 1] = temp;
	//		}
	//	}
	//}
	//printf("\n");
	//printf("%d\n", i);
	//for (int i = 0; i < n; i++) {
	//	printf("%d", a[i]);
	//}

	//插入排序 从大到小排
	int i, j;
	for (i = 1; i < n; i++) {
		int temp = a[i];
		for (j = i; j > 0 && temp > a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	//作业2 优化冒泡排序

	//int temp;
	//int i;
	//for (i = 0; i < n - 1; i++) {
	//	int exchange = 0;
	//	for (int j = 0; j < n - 1 - i; j++) {
	//		if (a[j] < a[j + 1]) {
	//			temp = a[j];
	//			a[j] = a[j + 1];
	//			a[j + 1] = temp;
	//			exchange = 1;
	//		}
	//	}
	//	if (!exchange) {
	//		break;
	//	}
	//}
	//printf("\n");
	//printf("%d\n",i);
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", a[i]);
	//}


	/*                              练习                                       */


	//printf("%d\n", rand());

	////1-10随机数
	//for (int i = 0; i < 10; i++) {
	//	printf("%d\t", rand() % 10);
	//}

	//printf("\n");

	////10-20随机数
	//for (int i = 0; i < 10; i++) {
	//	printf("%d\t", rand() % 11 + 10);
	//}

	////如果要获取[m,n]随机数
	////要实现rand() % (n - m + 1) + m;

	//printf("\n");

	////获取小数
	//for (int i = 0; i < 10; i++) {
	//	printf("%f ", rand()  / 10.0);
	//}

	//练习1：构造数组，将所有元素反转后遍历输出
	//int n;
	//scanf("%d", &n);
	//int arr[MAX] = {0};
	//for (int i = 0; i < n; i++) {
	//	scanf("%d", &arr[i]);
	//}
	//for (int j = 0; j < n / 2; j++) {
	//	int temp = 0;
	//	temp = arr[j];
	//	arr[j] = arr[n - 1 - j];
	//	arr[n - 1 - j] = temp;

	//}
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", arr[i]);
	//}

	//练习2：交换两个数组
	//int arr[] = { 100,200,300 };
	//int arr2[] = { 10,20,30 };
	//for (int i = 0; i < 3; i++) {
	//	int temp = arr[i];
	//	arr[i] = arr2[i];
	//	arr2[i] = temp;
	//	printf("%d %d\n", arr[i], arr2[i]);
	//}

	//练习3：获取数组最大值及其下标
	//int n;
	//scanf("%d", &n);
	//int arr[MAX] = {0};
	////for (int i = 0; i < n; i++) {
	////	scanf("%d", &arr[i]);
	////}
	////随机数复赋值
	//for (int i = 0; i < n; i++) {
	//	arr[i] =  rand() % 100001;
	//}
	//int max = 0;
	//int index = 0;
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", arr[i]);
	//	if (arr[i] > max) {
	//		max = arr[i];
	//		index = i;
	//	}
	//}
	//printf("\n");
	//printf("%d %d", max, index);

	//练习4：获取次小值，及其下标
	//int n;
	//scanf("%d", &n);
	//int arr[MAX] = {0};
	////for (int i = 0; i < n; i++) {
	////	scanf("%d", &arr[i]);
	////}
	////随机数复赋值
	//for (int i = 0; i < n; i++) {
	//	arr[i] =  rand() % 100001;
	//}
	////int min = INT_MAX;
	////int next_min = INT_MAX;
	////int index = 0;
	////int next_index = 0;

	//int min = arr[0] < arr[1] ? arr[0] : arr[1];
	//int next_min = arr[0] < arr[1] ? arr[1] : arr[0];
	//int index = arr[0] < arr[1] ? 0 : 1;
	//int next_index = arr[0] < arr[1] ? 1 : 0;
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", arr[i]);
	//	if (arr[i] < min) {
	//		next_min = min;
	//		next_index = index;
	//		min = arr[i];
	//		index = i;
	//	}
	//	else if (arr[i] < next_min && arr[i] > min) {
	//		next_min = arr[i];
	//		next_index = i;
	//	}
	//}
	//if (n == 1) {
	//	next_min = arr[0];
	//	next_index = 0;
	//}
	//printf("\n");
	//printf("%d %d", next_min, next_index);

	//练习5：模拟掷骰子10000次，统计每个面的情况

	/*int sum_1 = 0, sum_2 = 0, sum_3 = 0, sum_4 = 0, sum_5 = 0, sum_6 = 0;
	for (int i = 0; i < 10000; i++) {
		int result = rand() % 7;
		switch (result) {
			case 1:
				sum_1++;
				break;
			case 2:
				sum_2++;
				break;
			case 3:
				sum_3++;
				break;
			case 4:
				sum_4++;
				break;
			case 5:
				sum_5++;
				break;
			case 6:
				sum_6++;
				break;
		}
	}
	printf("%d %d %d %d %d %d", sum_1, sum_2, sum_3, sum_4, sum_5, sum_6);*/

	//用数组保存
	//int count[6] = { 0 };
	//for (int i = 0; i < 10000; i++) {
	//	int index = rand() % 6;
	//	count[index]++;
	//}
	//for (int i = 0; i < 6; i++) {
	//	printf("%d ", count[i]);
	//}
	return 0;
}