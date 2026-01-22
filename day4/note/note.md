# 嵌入式学习
## 循环结构

### for循环

#### 语法：
```
for (循环变量;循环条件;操作表达式){
    循环体;
}
```

#### 执行思路：
    1、先执行循环变量
    2、判断循环条件
    3、执行循环体
    4、执行操作表达式
    5、判断循环条件（满足继续循环，不满足退出循环）

#### 示例：
```
	//练习1：求1-20偶数和
	int sum = 0;
	for (int i = 1; i <= 20; i++) {
		if (i % 2 == 0)
		{
			sum += i;
		}
	}
	printf("%d", sum);

	//优化版本
	for (int i = 2; i <= 20; i += 2) {//这里也可通过乘2实现
		sum += i;
	}
	printf("%d", sum);

	//练习2：10阶乘
	long int result = 1;//虽然不会溢出，以防万一，开大点
	for (int i = 1; i <= 10; i++) {
		result *= i;
	}
	printf("%ld", result);


	//练习3：1-10阶乘和
	long int result = 1;
	long int sum = 0;
	for (int i = 1; i <= 10; i++) {
		result *= i;
		sum += result;
	}
	printf("%d", sum);

	//练习4：
	int m = 0, n = 0;
	scanf("%d%d", &m, &n);
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < m; i++) {
		temp = temp * 10 + n;
		//printf("%d ", temp);
		sum += temp;
	}
	printf("%d", sum);

	//练习5：求数字各个位之和
	int num;
	scanf("%d", &num);
	int sum = 0;
	//for (; num != 0;) {
	//	sum += num % 10;
	//	num /= 10;
	//}
	for (int i = num; i != 0; i /= 10) {
		sum += i % 10;
	}
	printf("%d", sum);
```

### while循环

#### 语法：
```
while （循环条件）{
    循环体;
}
```

#### 执行思路：
    当循环条件为真的时候就执行循环体，否则退出循环.

### do while循环

#### 语法：
```
do {
	循环体;
} while (循环条件);
```

#### 执行思路：


### break和continue

break：打破循环，终止循环的执行。

continue：停止本次循环，下一轮的循环还需要继续执行。


### for循环和while循环的区别
    一般在知道循环次数的时候会采用for循环
    在不确定循环次数的时候采用while会更多一些

### 双层for循环
