#include <stdio.h>

void find_day(int n) {
	switch (n % 7) {
	case 0:
		printf("%d天后是星期日", n);
		break;
	case 1:
		printf("%d天后是星期一", n);
		break;
	case 2:
		printf("%d天后是星期二", n);
		break;
	case 3:
		printf("%d天后是星期三", n);
		break;
	case 4:
		printf("%d天后是星期四", n);
		break;
	case 5:
		printf("%d天后是星期五", n);
		break;
	case 6:
		printf("%d天后是星期六", n);
		break;
	default:
		printf("ERREO");

	}
}