#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[3][2] = { {0},{0}, {0} };
	int(*p)[3][2] = &a;
	int i, j;
	for (i = 0; i < 3; i++) {
		int sum = 0;
		for (j = 0; j < 2; j++) {
			switch(j) {
				case 0:
					printf("正在输入第%d个同学的数学成绩:", i + 1);
					scanf("%d", *(*p + i) + j);
					sum += (*p)[i][j];
					break;
				case 1:
					printf("正在输入第%d个同学的语文成绩:", i + 1);
					scanf("%d", *(*p + i) + j);
					sum += (*p)[i][j];
					break;
			}
		}
		printf("第%d个同学的总成绩是：%d\n", i + 1, sum);
	}
}