#include <stdio.h>

int main(int argc, char *argv[]) 
{
    double height;
    double width;
    double parameter;
    double area;

    printf("Input the height and the width of a recetangle: \n");
    scanf("%lf %lf", &height, &width);

    parameter = 2 * (height+width);
    area = height*width;

    printf("The area of the rectangle is: %.1lf\nThe parameter is: %.1lf\n", area, parameter);

    return 0;
}