#include <stdio.h>

int main()
{
    double minutesInDay = 24 * 60;
    double minutesInYear = 365 * minutesInDay;

    int inputMin;

    printf("Enter in the number of minuites: \n");
    scanf("%d", &inputMin);

    double minOfDay = minutesInDay / (double) inputMin;
    double minOfYear = minutesInYear / (double) inputMin;

    printf("\n%d is 1/%dth of a day\n", inputMin, (int) minOfDay);
    printf("\n%d is 1/%dth of a year\n", inputMin, (int) minOfYear);

    return 0;
}