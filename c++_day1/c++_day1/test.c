#include <stdio.h>
#include <string.h>

#define MAX 20


int IsAllDigit(char p[]) {
	int n = strlen(p);
	for (int i = 0; i < n; i++) {
		if (p[i] < '0' || p[i] > '9') {
			return 0;
		}
	}
	return 1;
}

int main()
{
	char s[MAX];
	printf("Please input a string:\n");
	gets(s);
	if (IsAllDigit(s)) {
		printf("The string is a digit string.");
	}
	else {
		printf("The string is not a digit string.");
	}
	return 0;
}