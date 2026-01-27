#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int* initArr(int n) {
	if (n < 1) {
		printf("数组大小必须大于0\n");
		return NULL;
	}
	int* arr = (int*)malloc(n *sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	return arr;
}


void printArr(int* arr, int n) {
	if (arr == NULL || n < 1) {
		printf("数组为空或者大小不合适\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// main中实参为ans，存入的内容是数组的地址
//如果只是用一级指针，（形参的值是复制实参的值，二者是独立的）形参存入的内容是数组的地址，free(arr)也即free(ans)，
//数组释放了，然后arr = NULL，只是改变了形参的值，实参ans仍指向数组的地址，但此时数组释放了，因此ans变成了野指针

//如果用二级指针，形参存入的是ans的地址，free(*arr)也即free(ans)，ans存的是数组地址，数组释放
//然后*arr = NULL，也即ans = NULL，改变了实参，实参没有变成野指针


void freeArr(int** arr) { // 需要通过二级指针绕过值传递，避免释放后，实参指针成为野指针
	if (arr == NULL || *arr == NULL) {
		printf("数组为空，无法再释放\n");
		return;
	}
	free(*arr);
	*arr = NULL;
}

void assignArr(int* arr, int n) {
	srand((unsigned int)time(NULL));
	if (arr == NULL || n < 1) {
		printf("数组为空或大小不合适\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

int * insertNum(int* arr, int* size, int num, int index) {//通过指针size传递数组大小，实现修改主函数中的数组大小；若size不用指针，修改仅作用于函数内形参，实参无变化
	int n = *size;
	if (arr == NULL || n < 1) {
		printf("数组为空或大小不合适\n");
		return arr;
		//返回原指针，避免指针丢失，防止内存泄漏
		//（内存泄漏是指：程序中动态分配的内存（通过malloc / calloc / realloc申请），在不再使用后，既没有被释放（free），
		//也丢失了指向这块内存的指针 → 这块内存永远无法被程序回收和复用，直到程序退出，系统才会回收。）
	}
	if (index < 0 || index >= n) {
		printf("Invalid index\n");
		return arr;
	}
	int * new_arr = (int*)realloc(arr, sizeof(int) * (n + 1));
	if (new_arr == NULL) {
		printf("内存分配失败");
		return arr;
	}
	for (int i = n; i > index; i--){
		new_arr[i] = new_arr[i - 1];
	}
	new_arr[index] = num;
	(*size)++;
	return new_arr;
}

int* deleteNum(int* arr, int* size, int index) {
	int n = *size;
	if (arr == NULL || n < 1) {
		printf("数组为空或大小不合适\n");
		return arr;
	}
	if (index < 0 || index >= n) {
		printf("Invalid index");
		return arr;
	}
	for (int i = index; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}

	int* new_arr = (int *)realloc(arr, sizeof(int) * (n - 1));
	if (new_arr == NULL) {
		printf("内存分配失败");
		return arr;
	}
	(*size)--;
	return new_arr;
}

int searchNum(int* arr, int n, int num) {
	if (arr == NULL || n < 1) {
		printf("数组为空或大小不合适\n");
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (num == arr[i]) {
			return i;
		}
	}
	return -1;
}

int main(){

	int n;
	scanf("%d", &n);
	int* ans1;
	//初始化
	ans1 = initArr(n);
	printArr(ans1, n);

	//赋值
	assignArr(ans1, n);
	printArr(ans1, n);

	//删除
	ans1 = deleteNum(ans1, &n, 1);
	printArr(ans1,n);

	//添加
	ans1 = insertNum(ans1, &n, 70, 1);
	printArr(ans1, n);

	//查找
	int result = searchNum(ans1, n, 70);
	printf("%d\n", result);

	//释放
	freeArr(&ans1);

	return 0;

}