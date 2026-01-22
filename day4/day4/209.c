#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
	int min_len = INT_MAX;
	for (int i = 0; i < numsSize; i++) {
		int sum = 0;
		for (int j = i; j < numsSize; j++) {
			sum += nums[j];
			if (sum >= target) {
				int current_len = j - i + 1;
				if (current_len < min_len) {
					min_len = current_len;
				}
			}
		}
	}
	return min_len == INT_MAX ? 0 : min_len;
}

int main() {
	int* nums = (int*)malloc(sizeof(int) * 8);
	nums[0] = 1;
	nums[1] = 1;
	nums[2] = 1;
	nums[3] = 1;
	nums[4] = 1;
	nums[5] = 1;
	nums[6] = 1;
	nums[7] = 1;
	int x = minSubArrayLen(11, nums, 8);

	printf("满足条件的最小子数组长度：%d\n", x);  // 输出2（子数组[4,3]）

	// 4. 释放堆内存，避免内存泄漏
	free(nums);
	nums = NULL;
	return 0;

}