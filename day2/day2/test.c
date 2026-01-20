#include <stdio.h>
#include "major1.h"

int main() {
	//int test1;
	//scanf("%d", &test1);
	//printf("%d", num_add(test1));
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", find_mid(a, b, c));







	//double x = 32.2000;
	//float y = 15.22345650000;
	//printf("%lf\n%f\n", x,y);
	//printf("%g\n",x);
	//double num = 123456783;
	//printf("%g", num);
	//char a = 'A';
	//a = a + 32;
	//printf("%c", a);

	//字符输入并转化为小写字母
	//int c;
	//while ((c = getchar()) != '\n'){
	//	if (c >= 65 && c <= 90) {
	//		c = c + 32;
	//	}
	//	if (c != '\n') {
	//		printf("%c", c);
	//	}
	//}

	//return 0;
	//int a = 10, b = 20, c = 30;
	//int arr[3] = { a,b,c };
	//int* p_arr[3] = {&arr[1],&arr[0],&arr[2]};
	////for (int i = 0; i < 3; i++) {
	////	printf("%d ", *p_arr[i]);
	////}
	//int(*p_arr1)[3] = &arr;
	//printf("%p ,%p ,%p\n", p_arr1,p_arr1+1,arr+1);
	//printf("%d\n", sizeof(p_arr1));
	//char s[3] = { "sad"};
	//char (*p)[3] = &s;
	//printf("%p ,%p\n", p, p + 1);
	//printf("%d", sizeof(p));

	//int res = 0 ? 200 : 300;
	//printf("%d", res);

	//练习1：从控制台输入两个数，输出较大数
	//int num1, num2;
	//scanf("%d%d", &num1, &num2);
	//printf("%d", num1 > num2 ? num1 : num2);

	//练习2：从三个数中选出最小数
	//int num1, num2, num3;
	//scanf("%d%d%d", &num1, &num2, &num3);
	//int result1 = num1 < num2 ? num1 : num2;
	//int result2 = num1 < num3 ? num1 : num3;
	//printf("%d", result1 < result2 ? result1 : result2);
	//printf("%d", num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3));

	return 0;
}