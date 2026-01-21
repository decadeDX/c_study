#include <stdio.h>
#include <string.h>
#include "major1.h"
#include "major2.h"
#include "major3.h"

//int maxScore(char* s) {
//    int max = 0,score_left = 0;
//    for (int i = 0; i < strlen(s); i++) {
//        int score_right = 0;
//        if (s[i] == '0') {
//            score_left += 1;
//        }
//        for (int j = i + 1; j < strlen(s); j++) {
//            if (s[j] == '1') {
//                score_right += 1;
//            }
//        }
//        if (score_left + score_right > max) {
//            max = score_left + score_right;
//        }
//    }
//    return max;
//}



int main() {
    //char* s;
    //int n;
    //scanf("%d", &n);
    //s = (char*)malloc(sizeof(char) * n);
    //scanf("%s", s);
    //printf("%d", maxScore(s));


    //练习1：大写转小写
    //char ch1;
    //while ((ch1 = getchar()) != '\n') {
    //    ch1 |= 0x20;
    //    printf("%c", ch1);
    //}

    //练习2：小写转大写
    //char ch2;
    //while ((ch2 = getchar()) != '\n') {
    //    ch2 &= ~0x20;
    //    printf("%c", ch2);
    //}

    //练习3:大写转小写，小写转大写
    //char ch3;
    //while ((ch3 = getchar()) != '\n') {
    //    ch3 ^= 0x20;
    //    printf("%c", ch3);
    //}

    /*
    * a  0110 0001
    * 32 0010 0000
    * A  0100 0001
    */

    ////练习
    //int a, b;
    //printf("请输入a:");
    //scanf("%d", &a);
    //printf("请输入b:");
    //scanf("%d", &b);
    //printf("交换前 a = %d,b = %d\n", a, b);
    //int temp;
    //temp = a;
    //a = b;
    //b = temp;
    //printf("交换后 a = %d,b = %d\n", a, b);
    ////printf("交换后a = %d,b = %d", b, a);

    ////练习：右数第M位是否为1
    //int x;
    //scanf("%d", &x);
    //int m;
    //scanf("%d", &m);
    ////方法一
    //x & (1 << m - 1) ? printf("yes") : printf("no");

    ////方法二
    //x >> m - 1 & 1 ? printf("yes") : printf("no");
    ////if (x & (1 << m - 1)) printf("yes");
    ////else printf("no");

    
    //练习
    //char ch;
    //scanf("%c", &ch);
    //if (ch >= 'A' && ch <='Z') {
    //    printf("%c是大写字母", ch);
    //}
    //else if (ch >= 'a' && ch <= 'z') {
    //    printf("%c是小写字母", ch);
    //}
    //else if (ch >='0' && ch <= '9') {
    //    printf("%c是数字", ch);

    //}
    //else if ((ch >= 0 && ch <= 32) || ch == 127) {
    //    printf("是不可见字符");
    //}
    //else {
    //    printf("是除数字、大小写字母外的字符");
    //}
    //return 0;

    //练习
    //int score;
    //scanf("%d", &score);
    //if (score < 0 || score > 100) {
    //    printf("不合法");
    //}
    //else if (score < 60) {
    //    printf("E");
    //}
    //else if (score < 70) {
    //    printf("D");
    //}
    //else if (score < 80) {
    //    printf("C");
    //}
    //else if (score < 90) {
    //    printf("B");
    //}
    //else {
    //    printf("A");
    //}


    //练习：判断闰年
    //int year;
    //scanf("%d", &year);
    //if (year % 400 == 0) {
    //    printf("%d是世纪闰年",year);
    //}
    //else if (year % 100 != 0 && year % 4 == 0) {
    //    printf("%d是普通闰年",year);
    //}
    //else {
    //    printf("%d是平年",year);
    //}



    //判断合法日期
    //int year, month, date;
    //scanf("%d%d%d", &year, &month, &date);
    //int flag = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
    //if (month > 0 && month < 13) {
    //    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (date > 31 || date < 1)) {
    //            printf("不合法");
    //    }
    //    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (date > 30 || date < 1)){
    //            printf("不合法");
    //    }
    //    else {
    //        if (flag && date > 29) {
    //            printf("不合法");
    //        }
    //        else if (!flag && date >28) {
    //            printf("不合法");
    //            }
    //        else {
    //            printf("合法");
    //        }
    //    }
    //}
    //else {
    //    printf("不合法");
    //}

    //四则运算
    //int x, y;
    //char op;
    //scanf("%d%c%d",&x, &op, &y);
    //switch (op) {
    //case '+':
    //    printf("%d + %d = %d", x, y, x + y);
    //    break;
    //case '-':
    //    printf("%d - %d = %d", x, y, x - y);
    //    break;
    //case '*':
    //    printf("%d * %d = %d", x, y, x * y);
    //    break;
    //case '/':
    //    printf("%f / %f = %f", (float)x, (float)y, (float)x / y);
    //    break;
    //default:
    //    printf("非法操作");
    //}
    int n;
    scanf("%d", &n);
    find_day(n);
    printf("\n");
    Grade_sort(n);
    return 0;
}