#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//练习1：在hello c++中查找o的下标
void test1() {
	char  s[] = "hello C++";
	const char * index = strchr(s, 'o');
	printf("下标是%d\n", index - s);
}

//练习2：输入一个字符串，查找a的个数
void test2(char* s) {
	int count = 0;
	char* tmp = strchr(s, 'a');
	while (tmp) {
		count++;
		tmp = strchr(tmp + 1, 'a');
	}
	printf("个数是%d\n", count);
}

//练习3：查找字符串出现次数
void test3(char * s) {
	int count = 0;
	char* tmp = strstr(s, "bab");
	while (tmp) {
		count++;
		//tmp = strstr(tmp + 3, "bab");//查找到字符串下一个位置，babab只算一次
		tmp = strstr(tmp + 1, "bab");//查找到字符串下一个位置，babab算两次
	}
	printf("个数是%d\n", count);
}


//练习4:输入一个英文句子，判断出现最多的字母及其出现次数
const char* str = "abcdefghijklmnopqrstuvwxyz";

int cmp(const void* a, const void* b) {
	return (const int*)a - (const int*)b;//
}
void test4(char* s) {
	int size = strlen(str);
	int* count = (int *)calloc(size,sizeof(int));
	for (int i = 0; i < size; i++) {
		char* tmp = strchr(s, str[i]);
		while (tmp) {
			count[i]++;
			tmp = strchr(tmp + 1, str[i]);
		}
	}
	int max = count[0], pos = 0;
	for (int i = 0; i < size; i++) {
		printf("%d ", count[i]);
		if (max < count[i]) {
			max = count[i];
			pos = i;
		}
	}
	printf("\n");
	printf("出现次数最多的字母是%c,其出现次数是%d\n", 'a' + pos, max);

	free(count);

}

//练习5：找出数字，并求和：asdf123b1 -> 1 + 2 + 3 + 1 = 7
void test5(char* s) {
	//方法一
	/*int count[128] = { 0 };
	for (int i = 0; i < strlen(s); i++) {
		count[s[i]]++;
	}
	int sum = 0;
	for (int i = 49; i <= 57; i++) {
		sum += count[i] * (i - 48);
	}*/

	//方法二
	int sum = 0;
	for (int i = 0; s[i]; i++) {
		if (isdigit(s[i])) {
			sum += s[i] - 48;
		}
	}
	printf("%d\n", sum);
}

//练习6：连续数字串当成一个完整数字asdf123b1 -> 123 + 1 = 124
void test6(char* s) {
	int sum = 0;
	int i = 0;
	/*while (s[i] != '\0') {
		if (isdigit(s[i])) {
			int current_num = 0;
			while (s[i] != '\0' && isdigit(s[i])) {
				current_num = current_num * 10 + s[i] - '0';
				i++;
			}
			sum += current_num;
		}
		else i++;
		
	}*/
	int tmp = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			tmp = tmp * 10 + s[i] - '0';
		}
		else {
			sum += tmp;
			tmp = 0;
		}
	}
	sum += tmp;
	printf("%d\n", sum);
}

//练习7:找连续出现次数最多的字符及其次数
void test7(char* s) {
	if (s == NULL || *s == '\0') {
		printf("输入字符串无效");
		return;
	}
	int current_count = 1;//当前字符串长度
	int max_count = 1;//最大连续字符串长度
	int max_ch = s[0];//最大连续字符串的字符
	int len = strlen(s);
	for (int i = 1; i < len; i++) {
		if (s[i] == s[i - 1]) {
			current_count++;//如果相同当前字符串长度加一
		}
		else {
			current_count = 1;//如果不同，当前字符串长度置为1
		}
		if (max_count < current_count) {//如果当前字符串长度比最大连续字符串长度长就更新
			max_count = current_count;
			max_ch = s[i - 1];
		}
	}
	printf("%c\t%d", max_ch, max_count);
}

//练习8:反转英文句子
//方法一:使用分割
//void test8(char* s) {
//	char** str = (char**)calloc(100, sizeof(char *));
//	char* tmp = strtok(s, " ");
//	str[0] = tmp;
//	int word = 0;
//	while (tmp) {
//		str[word] = tmp;
//		word++;
//		tmp = strtok(NULL, " ");
//
//	}
//	for (int i = word - 1; i >= 0; i--) {
//		printf("%s ", str[i]);
//	}
//	printf("\n");
//
//	free(str);
//	str = NULL;
//}

//方法二：每次将最后的单词添到另一个字符串后
void test8(char* s) {
	char tmp[200] = "";
	char* pos = strrchr(s, ' ');
	while (pos) {
		strcat(tmp, pos + 1);
		strcat(tmp, " ");
		*pos = '\0';
		pos = strrchr(s, ' ');
	}
	strcat(tmp, s);
	printf("%s\n", tmp);
}

//练习九
//支持负数
void test9(char* s) {
	int sum = 0;
	int i = 0;

	char op = '+';//默认开始为加法
	while (s[i] != '\0') {
		//负数标志,每次循环要置0	
		int is_neg = 0;

		//判断是否是负数
		if (s[i] == '-' && (i == 0 || !isdigit(s[i - 1]))) {//这里或的先后顺序不能变，不然会出现越界情况
			is_neg = 1;
			i++;
		}
		//取数
		if (isdigit(s[i])) {
			int current_num = 0;
			while (s[i] != '\0' && isdigit(s[i])) {
				current_num = current_num * 10 + s[i] - '0';
				i++;
			}
			if (is_neg) {
				current_num = -current_num;
			}
			if (op == '+') {
				sum += current_num;
			}
			else {
				sum -= current_num;
			}
		}
		else {
			if (s[i] == '+' || s[i] == '-') {
				op = s[i];
			}
			i++;

		}
		
	}
	printf("%d\n", sum);
}

//不能支持负数的情况
// 
// 
//int calculator(int a,int b,char op) {
//	switch (op) {
//		case '+':
//			return a + b;
//			break;
//		case '-':
//			return a - b;
//			break;
//	}
//}
//void test9(char* s) {
//	int sum = 0;
//	int i = 0;
//	int count = 0;
//	int num[2] = { 0 };
//	char op;
//	while (s[i] != '\0') {
//		if (isdigit(s[i])) {
//			int current_num = 0;
//			while (s[i] != '\0' && isdigit(s[i])) {
//				current_num = current_num * 10 + s[i] - '0';
//				i++;
//			}
//			num[count++] = current_num;
//		}
//		else {
//			op = s[i];
//			i++;
//			if (count == 2) {
//				count = 1;
//				num[0] = sum;
//			}
//		}
//		if (count == 2) {
//			sum = calculator(num[0], num[1], op);
//		}
//
//	}
//	printf("%d\n", sum);
//}




int main() {
	
	//test1();
	//char* s = "asdfgsafsafdsad";
	//test2(s);

	const char* s1 = "dbabasdbabababs";
	//test3(s1);

	char ch;
	char* s2 = NULL;  // 初始化为 NULL，避免野指针
	int i = 0;
	
	s2 = (char*)malloc(32 * sizeof(char));
	while ((ch = getchar()) != '\n') {
		
		if (i >= (32 * (i / 32 + 1)) - 1) {
			// 扩容为原来的 2 倍
			char* temp = (char*)realloc(s2, (i / 32 + 1) * 64 * sizeof(char));
			if (temp == NULL) {
				printf("内存扩容失败！\n");
				free(s2);  // 释放已分配的内存，避免内存泄漏
				return 1;
			}
			s2 = temp;
		}
		s2[i] = ch;
		i++;
	}
	s2[i] = '\0';

	//test4(s2);
	//test5(s2);

	//test6(s2);
	//test7(s2);
	//test8(s2);
	test9(s2);

	free(s2);
	s2 = NULL;
}