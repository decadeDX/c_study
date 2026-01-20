#include <stdio.h>

int find_mid(int a, int b, int c) {
	int tmp1 = a < b ? (a < c ? a : c) : (b < c ? b : c);
	int tmp2 = a > b ? (a > c ? a : c) : (b > c ? b : c);
	return a + b + c - tmp1 - tmp2;

}