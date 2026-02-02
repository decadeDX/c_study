#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Birthday {
	unsigned int year:16;
	unsigned int month:4;
	unsigned int day:4;
};


typedef struct Student {
	char* name;
	int age;
	struct Birthday birthday;
} student;

typedef struct Student1 {
	char* name;
	int age;
	double score[3];
} student1;

//定义函数计算结构体数组的平均分数
void getAvg(student1 *s) {
	double avg[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		double sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += s[i].score[j];
		}
		avg[i] = sum / 3;
		printf("第%d个同学的平均成绩是%lf\n", i + 1, avg[i]);
	}
	printf("\n");
}

//排序
int cmp(const void* a, const void* b) {
	const student1 * s1 = (const student1 *)a;
	const student1* s2 = (const student1 *)b;
	double score1 = s1->score[0] + s1->score[1] + s1->score[2];
	double score2 = s2->score[0] + s2->score[1] + s2->score[2];
	return (double)(score2 - score1);
}


void test4(student1* s, int n) {
	qsort(s, n, sizeof(s[0]), cmp);
	
	for (int i = 0; i < n; i++) {
		double sum = 0;
		printf("第%d个同学的成绩是\n",i + 1);
		for (int j = 0; j < 3; j++) {
			sum += s[i].score[j];
			printf("%lf ", s[i].score[j]);
		}
		printf("总成绩是%lf", sum);
		printf("\n");
	}
}

//练习
typedef struct Account {
	char* user_name;
	int  user_id;
	char* ID;
	int isOnline;
} User;


int user_id = 2025001;

void input(User * s, int n) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		printf("请输入用户名：\n");
		(s + i)->user_name = (char*)malloc(30 * sizeof(char));
		scanf("%s", (s + i)->user_name);
		(s+i)->user_id = user_id++;
		printf("用户id为%d\n", (s + i)->user_id);
		printf("请输入身份证号：\n");
		(s + i)->ID = (char*)malloc(30 * sizeof(char));
		scanf("%s", (s + i)->ID);
		printf("请选择在线状态：0：隐身、1：在线\n");
		scanf("%d", &(s+i)->isOnline);
	}
}

void output(User* s, int n) {
	printf("打印用户信息列表\n");
	for (int i = 0; i < n; i++) {
		printf("第%d个用户\n", i + 1);
		printf("用户名：%s\n", s[i].user_name);
		printf("用户id为:%d\n", s[i].user_id);
		printf("身份证号：%s\n", s[i].ID);
		printf("在线状态：%d\n", s[i].isOnline);
		printf("\n");
	}
}

void test6() {
	int n;
	printf("请输入创建的用户个数:\n");
	scanf("%d", &n);
	User* user = (User*)malloc(n * sizeof(User));
	input(user, n);
	output(user, n);
}


void  test7() {
	time_t currtime = time(NULL);
	struct tm* time = localtime(&currtime);
	printf("%d年%d月%d日 %d时%d分%d秒\n", time->tm_year + 1900,
		time->tm_mon + 1,
		time->tm_mday,
		time->tm_hour,
		time->tm_min,
		time->tm_sec);
}


void test8(int n) {
	enum weekday {
		day1 = 1,
		day2,
		day3,
		day4,
		day5,
		day6,
		day7,
	};
	switch (n) {
	case day1:
		printf("今天是周一\n");
		break;
	case day2:
		printf("今天是周二\n");
		break;
	case day3:
		printf("今天是周三\n");
		break;
	case day4:
		printf("今天是周四\n");
		break;
	case day5:
		printf("今天是周五\n");
		break;
	case day6:
		printf("今天是周六\n");
		break;
	case day7:
		printf("今天是周日\n");
		break;
	default:
		printf("输入错误，请输入1-7\n");
		return;

	}
}

int main() {
	//student s1 = { "asdf",25,{2002,1,30} };
	//printf("学生姓名是%s\n年龄是%d\n生日是%d/%d/%d\n", s1.name, s1.age, s1.birthday.year, s1.birthday.month, s1.birthday.day);
	student1 s[3] = {
		{"xiaoming",17,{14,44,47}},
		{"xiaohong",16,{14,64,45}},
		{"xiaogang",18,{23,54,56}}
	};
	//getAvg(s);
	//test4(s,3);
	//test6();
	//test7();
	//int n;
	//scanf("%d", &n);
	//test8(n);
	struct Birthday t1;
	printf("%d", sizeof(t1));
	return 0;
}