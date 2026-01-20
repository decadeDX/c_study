#include <stdio.h>

int num_add(int x){
	int result = 0;
	if (x < 1000 || x > 10000) {
		return -1;
	}
	while (x > 0) {
		result += x % 10;
		x /= 10;
	}
	return result;
}