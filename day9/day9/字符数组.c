#include <stdio.h>
#include <stdlib.h>


//int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
//	*returnSize = n;
//	returnColumnSizes = (int**)malloc(sizeof(int *) * n);
//	int** ans = (int**)malloc(n * sizeof(int*));
//	for (int i = 0; i < n; i++) {
//		returnColumnSizes[i] = n;
//		ans[i] = calloc(n, sizeof(int));
//	}
//	int x = 0, y = 0;
//	int num = 1;
//	int total = n * n;
//	while (num < total) {
//		while (y + 1 <= n && ans[x][y + 1] == 0) {
//			ans[x][y++] = num++;
//		}
//		while (x + 1 <= n && ans[x + 1][y] == 0) {
//			ans[x++][y] = num++;
//		}
//		while (y - 1 >= 1 && ans[x][y - 1] == 0) {
//			ans[x][y--] = num++;
//		}
//		while (x - 1 >= 1 && ans[x - 1][y] == 0) {
//			ans[x--][y] = num++;
//		}
//	}
//	return ans;
//}




int main() {
	//int n;
	//scanf("%d", &n);
	//int *ret = (int*)malloc(sizeof(int) * n);
	//int** ans = (int**)malloc(n * sizeof(int*));
	//for (int i = 0; i < n; i++) {
	//	(*ret)[i] = n;
	//	ans[i] = calloc(n, sizeof(int));
	//}
	// 
	// 
	
	////atoi
	//const char* p = "123";
	//printf("%d\n", atoi(p));

	//const char* q = "1.2344";
	//printf("%lf\n", atof(q));

	////memcpy
	//const char* str = "HIJKLM";
	//char ch[] = "abcdefg";
	////memcpy(ch, str, 4);
	////printf("%s", ch);

	////将hijk复制到ch的后4位上
	//memcpy(ch + 3, str, 4);
	//printf("%s\n", ch);
	//        

	////strcmp
	//const char* ch1 = "asdfgEbsc ";
	//const char* ch2 = "asdfGefsbs";
	//printf("%d\n", strcmp(ch1, ch2));

	////strchr
	//char* t1 = strchr(ch1, 's');
	//printf("%s\n", t1);
	//printf("%d\n", (t1 - ch1) / sizeof(ch1[0]));
	//char* t2 = strrchr(ch1, 's');
	//printf("%d\n", (t2 - ch1) / sizeof(ch1[0]));
	//printf("%s\n", t2);
	char str[1000] = "www.123.456.789.com";
	char ch[100][10] = { {0} };
	int i = 0;
	char* tmp = strtok(str,".");
	while (tmp) {
		strcpy(ch[i], tmp);
		printf("%s\t", tmp);
		i++;
		tmp = strtok(NULL, ".");
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s", ch[i]);
	}
	return 0;




}