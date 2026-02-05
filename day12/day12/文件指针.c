#include <stdio.h>
#include <stdlib.h>

void test01() {
	FILE* p = fopen("./test.txt", "r");
	fputs("sdaf", p);
	fclose(p);
}



void test02() {
	FILE* p = fopen("./test.txt", "rb+");
	char str[100];
	fgets(str,5, stdin);
	fclose(p);
	printf("%s\n", str);
}

void test03() {
	FILE* fp = fopen("./test.txt", "wb+");
	char str[100] = "123456789";
	fwrite(str, 1, 3, fp);
	fclose(fp);

	FILE* fp1 = fopen("./test.txt", "r");
	char str2[100] = "";
	fread(str2, 1, 8, fp1);
	printf("%s\n", str2);
	fclose(fp1);
}

void test05() {
	FILE* fp = fopen("./test.txt", "r");
	char str[5][20];
	int i = 0;
	while (!feof(fp)) {
		fgets(str[i], 20, fp);
		/*printf("%s\t%d\n", str, feof(fp));*/
		i++;
	}	
	fclose(fp);
	for (int i = 0; i < 3; i++) {
		printf("%s\n",str[i]);
	}
}


void test06() {
	FILE* p = fopen("./test.txt", "r");
	fseek(p, 0, SEEK_END);
	int pos = ftell(p);
	char ch = fgetc(p);
	printf("%d\t%c\n", pos, ch);
	fclose(p);
}

int main() {
	test06();
}