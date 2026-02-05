#include <stdio.h>

void test01()
{
	// 打开文件
	// D:\\test01.txt  代表在D盘符下创建test01.txt文件
	FILE* fp = fopen("d:\\test01.txt", "wb+");

	// 将内容写入到文件中
	fputs("123abc", fp);

	//关闭文件
	fclose(fp);
}

void test02()
{
	// 打开文件
	FILE* fp = fopen("test01.txt", "rb+");

	// 将文件中内容读取出来
	char str[100]; // 创建数组，将读取出来的文件内容保存到数组中
	//fgets(str, 3, fp);  // 这里写3代表读取2个字符，多一个是给字符串的结束标识留位置
	fgets(str, 100, fp);
	fclose(fp);
	printf("str = %s\n", str);
}

void test03()
{
	// 打开文件
	FILE* fp = fopen("test01.txt", "r");
	// fprintf(fp, "ABCDEFG");

	// 将单个字符写入到文件中
	// fputc('P', fp);

	// 获取单个字符
	char ch;
	ch = fgetc(fp);
	fclose(fp);
	printf("%c\n", ch);
}

void test04()
{
	FILE* fp = fopen("d:\\test01.txt", "wb+");
	char ch[100] = "abcdefg";
	fwrite(ch, 1, 5, fp);
	fclose(fp);

	FILE* fp1 = fopen("d:\\test01.txt", "rb");
	char ch1[100] = "";
	fread(ch1, 1, 3, fp1);
	fclose(fp1);
	printf("ch1 = %s\n", ch1);
}

void test05()
{
	FILE* fp = fopen("d:\\test.txt", "r");
	char ch[10][20];
	// 将每行读取出来的数据给保存下来，然后统一进行遍历
	int i = 0;
	while (!feof(fp))
	{
		// ch[i]拿到的是字符二维数组每一行的首地址，将字符串按照行的方式逐条保存到二维数组中
		fgets(ch[i], 20, fp);
		i++;
	}
	fclose(fp);
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", ch[i]);
	}
}

void test06()
{
	FILE* fp = fopen("d:\\test.txt", "r");
	// 获取第三个字符的内容
	//fseek(fp, 2, SEEK_SET);
	//int pos = ftell(fp);
	//char ch = fgetc(fp);

	// 获取最后一个字符的内容
	fseek(fp, -1, SEEK_END);
	int pos = ftell(fp);
	char ch = fgetc(fp);
	printf("pos = %d\n", pos);
	printf("ch = %c\n", ch);

	// 当调用了fgetc一类的函数时，会导致指针自动后移
	// 将指针从当前的位置向前移动一个单位，因为刚才fgetc将指针移动到了最后一个字符的后一个位置，从当前位置向前移动一位，就又回到了刚才的最后一个字符的指针位置
	fseek(fp, -1, SEEK_CUR);
	pos = ftell(fp);
	ch = fgetc(fp);
	printf("pos = %d\n", pos);
	printf("ch = %c\n", ch);


	// 将指针移动到文件的最后一个位置，就是字符的个数
	// 对于windows中的text文件来说，除了文件的最后一行，每一行的结尾都有两个隐藏字符，所以计算的字符个数要比实际有效的字符要多（行数-1）*2 个字符。
	fseek(fp, 0, SEEK_END);
	pos = ftell(fp);
	printf("len = %d\n", pos);
	fclose(fp);
	/*printf("pos = %d\n", pos);*/
	/*printf("ch = %c\n", ch);*/  
}
int main()
{
	test06();
	return 0;
}