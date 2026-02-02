#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

//作业1:随机数点名
void randomSelectStudent(const char* arr[], int n, int selectnum) {
	srand((unsigned int)time(NULL));
	int* isSelect = (int*)calloc(n, sizeof(int));
	int count = 0;
	while (count < selectnum) {
		int index = rand() % n;
		if (!isSelect[index]) {
			isSelect[index] = 1;
			count++;
			printf("%s\n", arr[index]);
		}
	}
}


double* score;
//作业2 二维数组成绩排序
int cmp(const void* a, const void* b) {//降序
	int index1 = *(const int*)a;
	int index2 = *(const int*)b;
	if (score[index1] > score[index2]) {
		return -1;
	}
	else if (score[index1] == score[index2]) {
		return 0;
	}
	else {
		return 1;
	}
}


void getAvg(int** arr, int n, int low, int high) {
	srand((unsigned int)time(NULL));
	double* res = (double*)calloc(n, sizeof(double));

	//设置下标数组，存储每个学生对应的下标
	int* pos = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		pos[i] = i;
	}

	//赋值
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % (high - low + 1) + low;
		}
	}

	//找平均值
	printf("\n");
	printf("排序前的成绩分布：\n");
	printf("\n");
	for (int i = 0; i < n; i++) {
		int min = INT_MAX, max = arr[i][0];
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] > max) {
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

	printf("\n");
	printf("平均分：\n");
	printf("\n");

	for (int i = 0; i < n; i++) printf("%lf ", res[i]);
	printf("\n");

	//排序
	score = res;
	qsort(pos, n, sizeof(int), cmp);

	printf("\n");
	printf("降序排序后的次序：\n");
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", pos[i]);
	}
	printf("\n");


	int** tmparr = (int**)calloc(n, sizeof(int*));
	int  * tmpres = (double*)calloc(n, sizeof(double));
	for (int i = 0; i < n; i++) {
		tmparr[i] = arr[i];//保存数组
		tmpres[i] = res[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = tmparr[pos[i]];//更新数组
		res[i] = tmpres[pos[i]];
	}

	printf("\n");
	printf("按平均分降序排序后的对应同学的成绩：\n");
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("按平均分降序排序后的对应同学的平均分：\n");
	printf("\n");

	for (int i = 0; i < n; i++) printf("%lf ", res[i]);

	free(tmpres);
	free(tmparr);
	free(pos);
	free(res);
}



int main() {
	const char* students[] = {
		"陈维欣","陈潇奇","陈源昆","丁鑫","段家隆","费郁浩",
		"郝咏棋","侯清元","康健","康正伟","李东昊","刘佳恒",
		"李玥","米日丁","彭博","乔根根","王涵","王鑫",
		"王永辉","吴坤","薛维哥","杨萌","杨涛","张辉",
		"张嘉晋","张坤","张梦娣","赵俊虎","赵培源","朱嘉诚","朱阅文"
	};
	printf("挑选学生人数：\n");
	int n;
	scanf("%d", &n);
	int total = sizeof(students) / sizeof(students[0]);
	randomSelectStudent(students, total, n);

	printf("输入学生人数\n");
	int num;
	scanf("%d", &num);
	printf("输入分数范围\n");
	int l, h;
	scanf("%d%d", &l, &h);
	int** arr2 = (int**)calloc(num, sizeof(int*));
	for (int i = 0; i < num; i++) {
		arr2[i] = (int*)calloc(10, sizeof(int));
	}
	getAvg(arr2, num, l, h);


	//释放空间
	for (int i = 0; i < num; i++) {
		free(arr2[i]);
	}
	free(arr2);

}

