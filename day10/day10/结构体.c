#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char* name;
	int age;
	double score;
}student;

int main() {
	student s1 = { "safd",18,89 };
	printf("%s\n%d\n%lf\n", s1.name, s1.age, s1.score);
	return 0;
}