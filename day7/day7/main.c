#include <stdio.h>
int isrunnian(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 1 : 0;
}
int month[13] = { 365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
    int year, mon, day;
    int count = 0;
    int year_sum = 365;
    int i, j;
    scanf("%4d-%2d-%2d", &year, &mon, &day);
    if (mon < 1 || mon > 12)
    {
        printf("Invalid input");
        return -1;
    }
    if (isrunnian(year))
    {
        month[2] = 29;
        month[0] = 366;
    }
    else {
        month[2] = 28;
        month[0] = 365;
    }
    if (day < 1 || day > month[mon])
    {
        printf("Invalid input");
        return -1;
    }
    for (i = 1990; i < year; i++)
    {
        count += isrunnian(i) ? 366 : 365;
    }
    for (j = 1; j < mon; j++)
    {
        count += month[j];
    }
    count = count + day - 1;
   
    if (count % 5 < 3)
    {
        printf("He is working");
    }
    else
    {
        printf("He is having a rest");
    }
    return 0;
}