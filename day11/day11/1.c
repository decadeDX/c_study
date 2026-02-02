#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80
#define min(a,b) ((a) < (b) ? (a) : (b))

int main()
{
    char* s = (char*)malloc(MAX * sizeof(char));
    // 判空：防止 malloc 分配失败
    if (s == NULL) {
        perror("malloc s failed");
        return -1;
    }
    printf("Input s\n");
    // 修复：读取长度改为 MAX，匹配分配的内存大小，防止溢出
    fgets(s, MAX, stdin);
    // 修复：去除 fgets 读取到的末尾 \n，避免干扰比较
    s[strcspn(s, "\n")] = '\0';

    char* t = (char*)malloc(MAX * sizeof(char));
    if (t == NULL) {
        perror("malloc t failed");
        free(s); // 释放已分配的 s，避免内存泄漏
        return -1;
    }
    printf("Input t\n");
    fgets(t, MAX, stdin);
    t[strcspn(t, "\n")] = '\0';

    int count = 0;
    int len_s = strlen(s);
    int len_t = strlen(t);
    int l = min(len_s, len_t);

    // 优化：循环条件简化为 count < l（逐字符比较到较短字符串的末尾）
    while (count < l) {
        if (s[count] == t[count]) {
            count++;
        }
        else if (s[count] < t[count]) {
            printf("string s<string t.\n");
            // 释放内存后返回，避免内存泄漏
            free(s);
            free(t);
            return 0;
        }
        else {
            printf("string s>string t.\n");
            free(s);
            free(t);
            return 0;
        }
    }

    // 补充：处理「一个字符串是另一个前缀」的场景
    if (len_s < len_t) {
        printf("string s<string t.\n");
    }
    else if (len_s > len_t) {
        printf("string s>string t.\n");
    }
    else {
        printf("string s=string t.\n");
    }

    // 修复：释放动态分配的内存，避免内存泄漏
    free(s);
    free(t);
    return 0;

}