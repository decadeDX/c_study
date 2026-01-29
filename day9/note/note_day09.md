#  嵌入式学习 c语言基础 day9：

# 回调函数：

## callback

就是回调函数，函数指针经常用于函数的参数列表中，表示向函数传入一个功能。（而不是简单的在一个函数中调用另外一个函数）

## qsort

- 是C标准库中提供一个快速排序的函数，包含在头文件*stdlib*

- 函数原型：

  ```c
  void qsort(void* Base, size_t NumOfElements, size_t SizeOfElements), int(*comfunc)(const void* , const void*));
  ```

  

  - Base：数组本身的地址

  - NumOfElements：数组中元素的个数

  - SizeOfElements：数组中每个元素的大小

  - comfunc：比较规则，其中第一个参数如果比第二个参数小，就返回负数，如果比第二个大就返回正数，相等返回0(默认升序)
  
    **返回值 > 0**：`qsort` 会认为 `arg1` 指向的元素 **大于** `arg2` 指向的元素，需要将 `arg1` 排在 `arg2` 的**后面**。
  
    **返回值 < 0**：`qsort` 会认为 `arg1` 指向的元素 **小于** `arg2` 指向的元素，需要将 `arg1` 排在 `arg2` 的**前面**。
  
    **返回值 = 0**：`qsort` 会认为 `arg1` 指向的元素 **等于** `arg2` 指向的元素，两者顺序保持不变（相对稳定，`qsort` 本身是不稳定排序，但等值元素顺序不主动调整）。

# 字符数组和字符串

## 输入输出缓冲区

## 输出缓冲区

- 就将临时存放的所有的待显示数据，直接输出到屏幕中

- 清除缓冲区的场景：

  - 1、当一个输出语句结束的

  - 2、输出缓冲区溢出（大小1k左右）

  - 3、程序结束

## 输入缓冲区

- 当用户敲下回车的时候，将临时数据放入输入缓冲区，然后由输入缓冲区按照各种类型规则将数据放入指定的变量中，已经成功取走的数据就清理掉，如果数据没有被取走，就会一直存放在缓冲区中。

注意点：

由于输入缓冲区的规则是敲下回车的那一刻，所以输入缓冲区的最后一个字符一定是回车（换行）。

### 输入缓存区的读取规则：

- 1、%d/%f/%lf
  - 跳过所有的空白符（空格、回车、\t等等），遇到负号或者数字的时候才开始进行转化，遇到非数字的字符就停止，如果%f或者%lf会允许出现一个小数点，如果在转化的过程中没有遇到数字字符，就表示转化失败。

- 2、%c和getchar()
  - 无条件的读取缓存区中的一个字符，无论字符是什么都要。

- 3、%s
  - 跳过所有的空白符，遇到可见字符才开始接受，遇到空格或者回车就停止。

## 字符数组

### 概念

- 在程序中经常需要存储各种字符类型文本数据，比如：人名、住址等等，需要字符数组或者字符串来完成存储。

- ![image](D:\c_study\day9\note\1.png)

## 字符串系列常用函数

### 数字处理函数

##### atoi

- 在头文件 stdlib.h中

- 函数声明：int atoi(const char* str);

- 作用：将一个数字字符构成的字符串转化为int类型的整数返回

### 同类型的函数

- long类型     **atol(const char* str);**

- double类型   **atof(const char* str);**

### memset

- 函数原型：void* memset(const void* ptr, char val, size_t size);

- 作用：将内存中的一段空间全部赋给某个值，将ptr指向的位置之后的size个字节内容全部写成val

### memcpy

- 函数原型：void* memcpy(void* dst, const void* src, size_t size);

- 作用：将src所指向的位置后的size个字节复制到dst所指向的位置

### strlen

- 函数原型：size_t strlen(const char* str);

- 作用：计算str字符串的长度，不包括结束标识，只计算有效字符数

### strcpy和strncpy

- strcpy

  - 函数原型：char* strcpy(char* dst, const char* src);

  - 作用：将src指向字符串复制给dst，然后返回dst

- strncpy

  - 函数原型：char* strncpy(char* dst, const char* src, int n);

  - 将src指向字符串的前n个字符复制给dst，然后返回dst

### strcat和strncat

- strcat

  - 函数原型：char* strcat(char* dst, const char* src);

  - 作用：将src拷贝到dst的结尾处，拼接dst和src

- strncat

  - 函数原型：char* strcat(char* dst, const char* src, int n);

  - 作用：将src的前n个字符拷贝到dst的结尾处

### strcmp和strncmp

- strcmp

  - 函数原型：int strcmp(const char* s1, const char* s2);

  - 作用：比较两个字符串的大小， 如果前面比后面大，就返回正数，如果前面比后面小就返回负数，如果一样大就返回0

  - 比较原则：逐个比较两个字符串的字符，直到遇到第一个不相同的字符，比较其对应的ASCII码值，哪个字符的ASCII码值更大，那么就直接决定哪个字符串大，后面的字符就不再比较了。如果比较到了两个字符串的结尾值都一样，就说明两个字符串相等

- strncmp

  - 函数原型：int strcmp(const char* s1, const char* s2, int n);

  - 比较两个字符串的前n个字符的大小

### 查找类函数

- strchr

  - 函数原型：char* strchr(const char* src, char f);

  - 作用：在字符串src中查找字符f第一次出现的位置

- strrchr

  - 函数原型：char* strrchr(const char* src, char f);

  - 作用：在字符串src中查找字符f最后一次出现的位置

- strstr

  - 函数原型：char* strstr(const char* src, const char* f);

  - 作用：在字符串src中查找字符串f第一次出现的位置

- strpbrk

  - 函数原型：char* strpbrk(const char* src, const char* f);

  - 作用：在字符串src中找字符串f中任意一个字符第一次出现的位置

- 以上四个函数，如果找到元素就返回相应的地址，否则就返回NULL（空）

### strtok

- 函数原型：char* strtok(const char* src, const char* delim);

- 作用：根据分割字符集delim的字符，分割字符串src，只需要传递一次src就可以了，后面传空，就可以不断的去分割一个字符串，直到字符串不能再分割就返回空。