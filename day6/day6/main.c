#include <stdio.h>
#include <stdlib.h>


//作业1;定义一个函数，根据传递的实参的值，来打印相应行数的菱形，比如输入的数字为5（要求行数为奇数行)																			  //=
//    
// 
// 
void print(int n) {
	if (n % 2 == 0) {
		printf("非法输入，请输入奇数");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i <= n / 2) {
			for (int j = 0; j < n / 2 - i; j++) {
				printf(" ");
			}
			for (int j = 1; j <= 2 * i + 1; j ++) {
				printf("0");
			}
			printf("\n");
		}
		else {
			
			for (int j = 0; j < i - n / 2; j++) {
				printf(" ");
			}
			int k = n - i - 1;
			for (int j = 1; j <= 2 * k + 1; j ++) {
				printf("0");
			}
			printf("\n");
		}
	}
}

//作业2:数组旋转
void arrturn(int arr[], int arrsize, int num) {
	int count = num % arrsize;//类似冒泡排序，将最后的移动至最前
	for (int i = 0; i < count; i++) {
		for (int j = arrsize - 1; j > 0; j--) {
			int tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}
	}
}
//0 1 2 3 4   5 
//4 0 1 2 3   1
//3 4 0 1 2   2
//2 3 4 0 1   3
//1 2 3 4 0   4

int main() {
	////二分法查找
	//int n, target;
	//scanf("%d%d", &n, &target);
	//int* a = (int*)malloc(sizeof(int) * n);
	//for (int i = 0; i < n; i++) {
	//	scanf("%d",a + i);
	//}
	//int low = 0, high = n - 1;
	//int flag = 0;
	//int result = 0;
	//while (low <= high) {
	//	int mid = low + (high - low) / 2;
	//	if (a[mid] > target) {
	//		high = mid - 1;
	//	}
	//	else if (a[mid] < target) {
	//		low = mid + 1;
	//	} 
	//	else {
	//		flag = 1;
	//		result = mid;
	//		break;
	//	}
	//}
	//if (flag) {
	//	printf("%d", result);
	//} else{
	//	printf("未查找到数据");
	//}
	//free(a);
	//a = NULL;
	int n;
	//scanf("%d", &n);
	//print(n);
	int arr[] = { 1,2,3,4,5 };
	arrturn(arr, 5, 4);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	return 0;

}