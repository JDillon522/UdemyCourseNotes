#include <stdio.h>

int main()
{
    // Randomly hardcoded five years worth of rainfall by month
    float weather[5][12] = {
        // jan  feb  mar   apr  may  jun  july   aug  sep  oct  nov   dec
        {  0.5,  10,   4, 0.33,  22,  19,    7,   12,   0,  22,  11, 0.12 }, // 2010
        {  0.7,   6,   8,    7,   0,   5,    3,    2,   6,   9,   8,    2 }, // 2011
        {    3, 0.4, 0.3, 0.03, 0.1,   2, 0.45,    1,  10,   3,   6,  0.2 }, // 2012
        {    9,   8,   4,   77,   6,  12,    2,    2,   0,  19,  77, 0.55 }, // 2013
        {  0.5,  10,   4, 0.33,  22,  19,    7,   12,   0,  22,  11, 0.12 }  // 2014
    };


    // Output total yearly raifall
    /**
     * Year  Rainfall
     * 2010  ###
     * 2011  ###
     */
    float yearlyTotals[5];

    for (int i = 0; i < 5; i++)
    {
        float yearlyTotal = 0;

        for (int j = 0; j < 12; j++)
        {
            yearlyTotal += weather[i][j];
        }
        yearlyTotals[i] = yearlyTotal;
    }
    
    printf("YEAR RAINFALL\n");
    for (int i = 0; i < 5; i++)
    {
        printf("201%d %.2f\n",i, yearlyTotals[i]);
    }
    printf("\n\n");
    
    // Output the yearly average of the last five years 
    float totalRainfall = 0;
    for (int i = 0; i < 5; i++)
    {
        totalRainfall += yearlyTotals[i];
    }

    printf("The yearly average is %.2f inches of rain.\n\n", totalRainfall / 5);

    // Output the monthly averages
    /**
     *  Jan Feb Mar ...
     *  7.3 12  5
     */
    printf("MONTHLY AVERAGES:\n");
    float monthlyTotals[12];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            monthlyTotals[j] += weather[i][j];
        }
    }
    
    printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%.1f ", monthlyTotals[i] / 5);
    }
    
    printf("\n\n\n");


    return 0;
}