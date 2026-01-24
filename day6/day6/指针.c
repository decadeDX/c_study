#include <stdio.h>
#include <stdlib.h>

int main() {
	int num1 = 100;
	double num2 = 22.22;
	int* p = &num1;
	printf("%d\n", *p);
	printf("%p\n", p);
	printf("%p\n", &num1);

	int** p1 = &p;
	int*** p2 = &p1;
	printf("%p\t%p\t%p", *p, **p1, ***p2);
}

