#include <stdio.h>
#include <stdlib.h>

int main() {
	//练习1：求1-20偶数和
	//int sum = 0;
	//for (int i = 1; i <= 20; i++) {
	//	if (i % 2 == 0)
	//	{
	//		sum += i;
	//	}
	//}
	//printf("%d", sum);

	//优化版本
	//for (int i = 2; i <= 20; i += 2) {//这里也可通过乘2实现
	//	sum += i;
	//}
	//printf("%d", sum);

	//练习2：10阶乘
	//long int result = 1;//虽然不会溢出，以防万一，开大点
	//for (int i = 1; i <= 10; i++) {
	//	result *= i;
	//}
	//printf("%ld", result);


	//练习3：1-10阶乘和
	//long int result = 1;
	//long int sum = 0;
	//for (int i = 1; i <= 10; i++) {
	//	result *= i;
	//	sum += result;
	//}
	//printf("%d", sum);

	//练习4：
	//int m = 0, n = 0;
	//scanf("%d%d", &m, &n);
	//int sum = 0;
	//int temp = 0;
	//for (int i = 0; i < m; i++) {
	//	temp = temp * 10 + n;
	//	//printf("%d ", temp);
	//	sum += temp;
	//}
	//printf("%d", sum);

	//练习5：求数字各个位之和
	//int num;
	//scanf("%d", &num);
	//int sum = 0;
	////for (; num != 0;) {
	////	sum += num % 10;
	////	num /= 10;
	////}
	//for (int i = num; i != 0; i /= 10) {
	//	sum += i % 10;
	//}
	//printf("%d", sum);

	//练习6：
	//char* s = (char*)malloc(sizeof(char) * 6);
	//int num = 0;
	//do
	//{	
	//	if (num != 0) {
	//		printf("登陆失败，请重新输入密码:\n");
	//	}
	//	else {
	//		printf("请输入六位密码：\n");
	//	}
	//	scanf("%s", s);
	//	num += 1;
	//} while (strcmp(s, "123456"));
	//printf("登陆成功");

	//练习7：判断数字二进制有多少1
	// 方式一
	//int number;
	//scanf("%d", &number);
	//int count = 0;
	//unsigned int number_unsigned = (unsigned int)number; //优化、增添负数补码1的个数
	//while (number_unsigned > 0) {
	//	if ((number & 1) == 1) {
	//		count++;
	//	}
	//	number_unsigned = number_unsigned >> 1;
	//}
	//printf("%d", count);

	//方式二
	//int number;
	//scanf("%d", &number);
	//int count = 0;
	//while (number) {
	//	number &= number - 1;
	//	count++;
	//}
	//printf("%d", count);

	//练习8：判断回文数
	//int num;
	//scanf("%d", &num);
	//int sum = 0;
	//int temp = num;
	//while (temp){
	//	sum = sum * 10 + temp % 10;
	//	temp /= 10;
	//}
	//if (sum == num) {
	//	printf("%d是一个回文数", num);
	//}
	//else {
	//	printf("%d不是一个回文数", num);
	//}

	//练习1：
	//int flag = 0;
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 1; j <= 5; j++) {
	//		if (i == 1 && j == 3) {
	//			flag = 1;
	//			break;
	//		}
	//		printf("%d\t", j);
	//	}
	//	if (flag) {
	//		break;
	//	}
	//	printf("\n");
	//}

	//练习2：打印一个直角三角形
	//int h = 0;
	//scanf("%d", &h);
	//for (int i = 0; i < h; i++) {
	//	for (int j = i + 1; j > 0; j--) {
	//		printf("0 ");
	//	}
	//	printf("\n");
	//}

	//打印一个倒三角
	//int h = 0;
	//scanf("%d", &h);
	//for (int i = h; i > 0; i--) {
	//	for (int j = i; j > 0; j--) {
	//		printf("%d", i);
	//	}
	//	printf("\n");
	//}

	//练习3：打印一个等腰三角形
	//int h = 0;
	//scanf("%d", &h);
	//for (int i = h; i > 0; i--) {
	//	for (int j = i - 1 ; j > 0; j--) {
	//		printf(" ");
	//	}
	//	for (int j = 1; j < 2 * (h - i + 1); j++) {
	//		printf("0");
	//	}
	//	printf("\n");
	//}

	//打印九九乘法表
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d * %d = %d\t ", j, i, i * j);

		}
		printf("\n");
	}
	return 0;
}