#include <stdio.h>

int main()
{
    double minutesInDay = 24.0 * 60.0;
    double minutesInYear = 365.0 * minutesInDay;

    int inputMin;

    printf("Enter in the number of minuites: \n");
    scanf("%d", &inputMin);

    double minOfDay = minutesInDay / (double) inputMin;
    double minOfYear = minutesInYear / (double) inputMin;

    // Not a good way to do this. yuck
    printf("\n%d is 1/%dth of a day or %3f%% of a day\n", inputMin, (int) minOfDay, (double) inputMin / minutesInDay);
    printf("\n%d is 1/%dth of a year or %3f%% of a year\n", inputMin, (int) minOfYear, (double) inputMin / minutesInYear);

    return 0;
}