#include <stdio.h>

//判断合法日期
void isTrue(int year, int month, int day) {

    //判断是否是闰年
    int flag = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);

    // 先将不合法的日期排除掉，剩下的都是合法的
    if (month >= 1 && month <= 12 &&  //月份合法
        ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day>= 1 && day <=31 //大月合法判断
        || (month == 4 || month == 6 || month == 9 || month == 11)  && day >= 1 && day <= 30  //小月合法判断
        || month == 2 && day >=1 && day <= 28 + flag)) //二月闰年与否合法判断
    {
        printf("合法\n");
    }
    else
    {
        printf("不合法\n");
    }

    //正向思考
    //if (month > 0 && month < 13) {
    //    //大月
    //    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date > 0 && date <= 31) {
    //        printf("合法");
    //    }
    //    //小月
    //    else if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 0 && date <= 30) {
    //        printf("合法");
    //    }
    //    //2月
    //    else {
    //        if (flag && date > 0 && date <= 29) {
    //            printf("合法");
    //        }
    //        else if (!flag && date > 0 && date <= 28) {
    //            printf("合法");
    //        }
    //        else {
    //            printf("不合法");
    //        }
    //    }
    //}
    ////月份非法
    //else {
    //    printf("不合法");
    //}

}

int main()
{
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
    isTrue(year, month, day);
    return 0;
}